#pragma once
//cq : circular queue
#include <iostream>
#include <string>
#include "stdlib.h"
using namespace std;

class CQ {
private:
	int *queue;
	int size;
	int front;
	int rear;
public:
	CQ();
	~CQ();
	void setSize(int size);
	bool enqueue(int data);
	bool isFull();
	bool isEmpty();
	int Next(int now);
	void display();
};

CQ::CQ() {
	front = rear = 0;
}

CQ::~CQ() {
	
}

void CQ::setSize(int s) {
	size = s+1;
	queue = new int[size];
}

bool CQ::isFull() {
	return Next(rear) == front;
}

bool CQ::isEmpty() {
	return front == rear;
}

int CQ::Next(int now) {
	return (now + 1) % size;
}

bool CQ::enqueue(int data) {
	if (isFull()) {
		return false;
	}
	rear = Next(rear);
	queue[rear] = data;
	return true;
}

void CQ::display() {
	for (int i = front+1; i <= rear; i++)
	{
		cout << queue[i] << " ";
	}
}

