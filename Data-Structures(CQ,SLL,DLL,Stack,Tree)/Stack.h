#pragma once
using namespace std;
class Stack {
private:
	int top;   // stack_top
	int item;  // stack_item
	int size;  // stack_size
	int* stack;    // stack 배열
	int* reverse_stack; // stack reverse 배열
public:
	Stack() {
		top = -1;
	}
	void setSize(int size);
	void push(int item);
	int pop();
	void reverse_display();
};

void Stack::setSize(int s) {
	size = s;
	stack = new int[s];
	reverse_stack = new int[s];
}

void Stack::push(int item)
{
	if (top == size - 1)
	{
		cout << "stack overflow" << endl;
	}
	else
	{
		top += 1;
		stack[top] = item;
	}
}

int Stack::pop()
{
	if (top == -1)
	{
		return -1;
	}
	else
		return stack[top--];
}

void Stack::reverse_display()
{
	int i;
	for (i = 0; i < size; i++)
		reverse_stack[i] = pop();
	for (i = 0; i < size; i++) {
		cout << reverse_stack[i] << " ";
	}
		
}