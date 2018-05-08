#pragma once
#ifndef H_StackADT
#define H_StackADT
//만약 선언되어 있지 않다면 선언하겠다.

template <class Type>
class stackADT
{
public:
	virtual void initializeStack() = 0;
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const Type& newItem) = 0;
	virtual Type top() const = 0;
	virtual void pop() = 0;
};

#endif