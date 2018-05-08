// 병욱5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "mystack.h"

using namespace std;
bool isOperator(char ch);
int performOperation(int op1, int op2, char op);
int getWeight(char ch);
void infix2postfix(char infix[], char postfix[], int size);

int main()
{
	while (true) {
		stackType<double> s(100);
		char infix[1000], buffer[15], postfix[1000];
		int i, op1, op2, len, j, x;
		gets_s(infix);
		int leninfix = strlen(infix);
		infix2postfix(infix, postfix, leninfix);
		cout << postfix << endl;
		int lenpostfix = strlen(postfix);
		j = 0;
		s.initializeStack();
		for (i = 0; i < lenpostfix; i++) {
			if (postfix[i] >= '0' && postfix[i] <= '9') {
				buffer[j++] = postfix[i];
			}
			else if (postfix[i] == ' ') {
				if (j > 0) {
					buffer[j] = '\0';
					x = atoi(buffer);
					s.push(x);
					j = 0;
				}
			}

			else if (isOperator(postfix[i])) {
				op1 = s.top();
				s.pop();
				op2 = s.top();
				s.pop();
				s.push(performOperation(op1, op2, postfix[i]));
			}
		}
		cout << s.top() << endl;
	}
	system("pause");
	return 0;
} //end printResult

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	else
		return false;
}


int performOperation(int op1, int op2, char op)
{
	int ans;
	switch (op) {
	case '+':
		ans = op2 + op1;
		break;
	case '-':
		ans = op2 - op1;
		break;
	case '*':
		ans = op2 * op1;
		break;
	case '/':
		ans = op2 / op1;
		break;
	}
	return ans;
}

int getWeight(char ch) {
	switch (ch) {
	case '/':
	case '*': return 2;
	case '+':
	case '-': return 1;
	default: return 0;
	}
}

void infix2postfix(char infix[], char postfix[], int size) {
	stackType<double> s(100);
	int weight;
	int i = 0;
	int k = 0;
	char ch;

	while (i < size) {
		ch = infix[i];
		if (ch == '(') {
			s.push(ch);
			i++;
			continue;
		}
		if (ch == ')') {
			while (!s.isEmptyStack() && s.top() != '(' &&
				weight <= getWeight(s.top())) {
				postfix[k++] = ' ';
				postfix[k++] = s.top();
				s.pop();
			}
			if (!s.isEmptyStack()) {
				s.pop();
			}
			i++;
			continue;
		}
		weight = getWeight(ch);
		if (weight == 0) {
			postfix[k++] = ch;
		}
		else {
			postfix[k++] = ' ';
			if (s.isEmptyStack()) {
				s.push(ch);
			}
			else {
				while (!s.isEmptyStack() && s.top() != '(' &&
					weight <= getWeight(s.top())) {
					postfix[k++] = s.top();
					postfix[k++] = ' ';
					s.pop();
				}
				s.push(ch);
			}
		}
		i++;
	}

	while (!s.isEmptyStack()) {
		postfix[k++] = ' ';
		postfix[k++] = s.top();
		s.pop();
	}
	postfix[k] = 0; 
}