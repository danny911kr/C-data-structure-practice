#pragma once
//SLL : Single Linked List = 단일 연결리스트
#include <iostream>
#include <string>
#include "stdlib.h"
using namespace std;

class Node {
	friend class SLL;
private:
	int data;
	Node *next;
	Node(int v, Node *n)
	{
		data = v;
		next = n;
	}
};

class SLL {
private:
	Node *head;
	Node* tail;
	int size;
public:
	SLL();
	~SLL();
	void add(int data);
	void reverse_display();
};

SLL::SLL(){
	head = tail = NULL;
}

SLL::~SLL() {
	cout << "list deleted" << endl;
}

void SLL::add(int data) {
	Node *node = new Node(data,nullptr);
	if (head == nullptr)
	{
		head = node;
	}
	else
	{
		tail->next = node;
	}
	tail = node;
	size++;
}

void SLL::reverse_display()
{
	Node *prev = NULL;
	Node *current = head;
	Node *next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	Node *scan = head;
	while (scan != NULL)
	{
		cout << scan->data << " ";
		scan = scan->next;
	}
}
