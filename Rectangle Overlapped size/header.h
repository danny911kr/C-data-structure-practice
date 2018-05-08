#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class Rectangle
{
private:
	float x1, y1, x2, y2; // ��ǥ
	float width, height; // �ʺ�, ����
public:
	Rectangle(); // ������
	void input();
	float getArea();
	float getx1();
	float gety1();
	float getx2();
	float gety2();
	~Rectangle(); // �Ҹ���
};

class Overlap
{
private:
	float rect1_x1 = 0, rect1_y1 = 0, rect1_x2 = 0, rect1_y2 = 0; // ù��° �簢���� ��ǥ����
	float rect2_x1 = 0, rect2_y1 = 0, rect2_x2 = 0, rect2_y2 = 0; // �ι�° �簢���� ��ǥ����

public:
	void init(Rectangle rect1, Rectangle rect2); // �ʱ�ȭ �Լ� : rect1, rect2�� ��ǥ������ �޾Ƽ� ���� �����鿡 �־��ش�.
	void overlaprect(Rectangle rect1, Rectangle rect2); // �󸶳� overlap �Ǿ����� ������ִ� �Լ�
};
