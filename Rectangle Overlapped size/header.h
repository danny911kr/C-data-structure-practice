#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class Rectangle
{
private:
	float x1, y1, x2, y2; // 좌표
	float width, height; // 너비, 높이
public:
	Rectangle(); // 생성자
	void input();
	float getArea();
	float getx1();
	float gety1();
	float getx2();
	float gety2();
	~Rectangle(); // 소멸자
};

class Overlap
{
private:
	float rect1_x1 = 0, rect1_y1 = 0, rect1_x2 = 0, rect1_y2 = 0; // 첫번째 사각형의 좌표값들
	float rect2_x1 = 0, rect2_y1 = 0, rect2_x2 = 0, rect2_y2 = 0; // 두번째 사각형의 좌표값들

public:
	void init(Rectangle rect1, Rectangle rect2); // 초기화 함수 : rect1, rect2의 좌표값들을 받아서 위의 변수들에 넣어준다.
	void overlaprect(Rectangle rect1, Rectangle rect2); // 얼마나 overlap 되었는지 출력해주는 함수
};
