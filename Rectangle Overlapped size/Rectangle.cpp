#include "header.h"

Rectangle::Rectangle() // �ƹ��͵� �Է¾��ϰ� ȣ���ϸ�
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
	cin >> x1; // x1��
	cin >> y1; // y1��
	cin >> x2; // x2��
	cin >> y2; // y2��
	
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
Rectangle::~Rectangle() {}; // �Ҹ��� ����

