// 병욱4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "stdlib.h"

using namespace std;

class Polynomial;
class Term
{
	friend Polynomial;
private:
	float coef; // 계수
	int exp; // 지수
};

class Polynomial {
public:
	Polynomial();
	Polynomial operator+(Polynomial b); //a+p.a b+p.a c+p.a
	Polynomial operator*(Polynomial b);
	void NewTerm(const float theCoeff, const int exp);
	float Eval(float x);
	void print();
	void init();

private:
	Term *termArray;
	int capacity;
	int terms;
	float evalresult;
};

Polynomial::Polynomial() {
	capacity = 1;
	terms = 0;
	termArray = new Term[capacity]; //
}

void Polynomial::init() {
	delete[] termArray;
}

void Polynomial::NewTerm(const float theCoeff, const int theExp) {
	if (terms == capacity) {
		capacity *= 2;
		Term *temp = new Term[capacity];
		copy(termArray, termArray + terms, temp);
		delete [] termArray;
		termArray = temp;
	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}

//연산자 오버로딩
Polynomial Polynomial::operator+(Polynomial b) {
	Polynomial c;
	int aPos = 0, bPos = 0;
	while ((aPos < terms) && (bPos < b.terms))
		if (termArray[aPos].exp == b.termArray[bPos].exp) {
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t) c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp) {
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	for (; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	for (; bPos < b.terms; bPos++)
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);

	return c;
}

Polynomial Polynomial::operator*(Polynomial b) {
	Polynomial d;
	for (int i = 0; i<b.terms; i++)
	{
		Polynomial c;
		for (int j = 0; j<terms; j++)
		{
			c.NewTerm(termArray[j].coef * b.termArray[i].coef, termArray[j].exp + b.termArray[i].exp);
		}
		d = c+d;
	}

	return d;
}

float Polynomial::Eval(float x) {
	float result = 0;
	for (int i = 0; i < terms; i++)
	{
		float temp = 1;
		for (int j = 0; j < termArray[i].exp; j++)
			temp *= x;
		result += (temp*termArray[i].coef);
	}
	evalresult = result;
	return result;
}

void Polynomial::print() {
	int i;
	if (terms)
	{
		for (i = 0; i < terms - 1; i++)
			cout << termArray[i].coef << "x^" << termArray[i].exp << "+";
		cout << termArray[i].coef << "x^" << termArray[i].exp << " ";
		cout << evalresult << endl;
	}
	else
		cout << " terminate ";

}

Polynomial* calculate(int T) {
	
	Polynomial* C = new Polynomial[T];
	string lhs;// 첫번째 다항식
	string rhs;// 두번째 다항식
	int choice; // 1: add, 2: multiplication
	float variable; // x 변수
	char term_seps[] = "+";
	char *term_token;
	int coef_term;
	int exp_term;
	int i = 0;

	while (i<T) {
		Polynomial A, B;
		cin >> lhs;
		term_token = strtok(&lhs[0], term_seps);
		while (term_token != NULL)
		{
			if (term_token[0] == 'x') {
				coef_term = 1;
				exp_term = 0;
				if (strstr(term_token, "^")) {
					exp_term = atoi(&term_token[2]);
				}
				else if (strstr(term_token, "x")) {
					exp_term = 1;
				}
				else {
					exp_term = 0;
				}
			}
			else {
				coef_term = atoi(&term_token[0]);
				exp_term = 0;
				if (strstr(term_token, "^")) {
					exp_term = atoi(&term_token[3]);
				}
				else if (strstr(term_token, "x")) {
					exp_term = 1;
				}
				else {
					exp_term = 0;
				}
			}
			A.NewTerm(coef_term, exp_term);
			term_token = strtok(NULL, term_seps);
		}


		cin >> rhs;
		term_token = strtok(&rhs[0], term_seps);
		while (term_token != NULL)
		{
			if (term_token[0] == 'x') {
				coef_term = 1;
				exp_term = 0;
				if (strstr(term_token, "^")) {
					exp_term = atoi(&term_token[2]);
				}
				else if (strstr(term_token, "x")) {
					exp_term = 1;
				}
				else {
					exp_term = 0;
				}
			}
			else {
				coef_term = atoi(&term_token[0]);
				exp_term = 0;
				if (strstr(term_token, "^")) {
					exp_term = atoi(&term_token[3]);
				}
				else if (strstr(term_token, "x")) {
					exp_term = 1;
				}
				else {
					exp_term = 0;
				}
			}
			B.NewTerm(coef_term, exp_term);
			term_token = strtok(NULL, term_seps);
		}

		cin >> variable;
		cin >> choice;
		if (choice == 1) {
			C[i] = A + B;
		}
		else if (choice == 2) {
			C[i] = A * B;
		}
		C[i].Eval(variable);
		i++;
	}
	return C;
}

int main() {
	
	int T; // testcase 갯수
	cin >> T;
	Polynomial* C = new Polynomial[T];
	C = calculate(T);

	for (int i = 0; i < T; i++) {
		C[i].print();
	}
	system("pause");
}
