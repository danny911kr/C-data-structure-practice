#include "header.h"

Rectangle::Rectangle() // 아무것도 입력안하고 호출하면
{
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
	width = 0;
	height = 0;
};
void Rectangle::input()
{
	cin >> x1; // x1값
	cin >> y1; // y1값
	cin >> x2; // x2값
	cin >> y2; // y2값
	
	width = abs(x1-x2);
	height = abs(y1-y2);
	getArea();
};

float Rectangle::getArea()
{
	return width*height;
};

float Rectangle::getx1()
{
	return x1;
};
float Rectangle::gety1()
{
	return y1;
};
float Rectangle::getx2()
{
	return x2;
};
float Rectangle::gety2()
{
	return y2;
};
Rectangle::~Rectangle() {}; // 소멸자 해제

