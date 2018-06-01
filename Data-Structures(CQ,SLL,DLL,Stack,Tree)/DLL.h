#pragma once
//DLL : Double Linked List = 단일 연결리스트
#include <iostream>
#include <string>
#include "stdlib.h"
using namespace std;

class Node_DLL {
	friend class DLL;
private:
	int data;
	Node_DLL *next;
	Node_DLL *prev;
	Node_DLL(int v, Node_DLL *n, Node_DLL *p)
	{
		data = v;
		prev = p;
		next = n;
	}
};

class DLL {
private:
	Node_DLL *head;
	Node_DLL* tail;
	int size;
public:
	DLL();
	~DLL();
	void add(int data);
	void reverse_display();
};

DLL::DLL(){
	head = tail = NULL;
}

DLL::~DLL() {
	cout << "list deleted" << endl;
}

void DLL::add(int data) {
	Node_DLL *node = new Node_DLL(data,nullptr,nullptr);
	if (tail == nullptr)
	{
		head = tail;
	}
	else
	{
		node->prev = tail;
		tail->next = node;
	}
	tail = node;
	size++;
}

void DLL::reverse_display()
{
	Node_DLL *scan = tail;
	while (scan != NULL)
	{
		cout << scan->data << " ";
		scan = scan->prev;
	}
}
