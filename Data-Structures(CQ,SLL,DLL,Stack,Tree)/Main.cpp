#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include "stdlib.h"
#include "Stack.h"
#include "SLL.h"
#include "DLL.h"
#include "CQ.h"
#include "Tree.h"

using namespace std;

int main() {

	int testcase; // 총 몇 케이스?
	int i = 0; // testcase 돌리는 변수
	int k = 0; // print for문 돌리는 변수
	ifstream inFile("input.txt");
	if (inFile.is_open()) {
		cout << "open" << endl;
	}
	else {
		cout << "closed" << endl;
	}
	inFile >> testcase;
	//Stack* stack = new Stack[testcase]; // STACK
	//SLL* sll = new SLL[testcase]; //SLL
	//DLL* dll = new DLL[testcase]; //DLL
	//CQ* cq = new CQ[testcase]; //CQ
	Tree* tree = new Tree[testcase];

	while (i < testcase) {
		int testnum;
		int j = 0; // 줄에 있는 숫자 돌리는 변수
		inFile >> testnum; // 한 줄에 몇개?
		//stack[i].setSize(testnum);  // STACK
		//cq[i].setSize(testnum); //CQ
		tree[i].setSize(testnum);
		while (j < testnum) {
			int input;
			inFile >> input;
			//stack[i].push(input); //STACK
			//sll[i].add(input); //SLL
			//dll[i].add(input); //DLL
			//cq[i].enqueue(input); //CQ
			tree[i].addNode(input);
			j++;
		}
		i++;
	}

	for (k = 0; k < testcase; k++)
	{
		cout << "case " << (k+1) << endl;
		//stack[k].reverse_display(); //STACK
		//sll[k].reverse_display(); //SLL
		//dll[k].reverse_display(); //DLL
		//cq[k].display();// CQ
		tree[k].Preorder(tree[k].getRoot());
		cout << endl;
	}

	system("pause");
	return 0;
}