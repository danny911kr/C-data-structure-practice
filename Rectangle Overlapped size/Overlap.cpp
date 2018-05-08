#include "header.h"

void Overlap::init(Rectangle rect1, Rectangle rect2)
{
	rect1_x1 = rect1.getx1();
	rect1_y1 = rect1.gety1();
	rect1_x2 = rect1.getx2();
	rect1_y2 = rect1.gety2();
	
	rect2_x1 = rect2.getx1();
	rect2_y1 = rect2.gety1();
	rect2_x2 = rect2.getx2();
	rect2_y2 = rect2.gety2();
}

void Overlap::overlaprect(Rectangle rect1, Rectangle rect2) {

	int i, j, overlaps = 0;
	int overlap_x1 = 0;
	int overlap_y1 = 0;
	int overlap_x2 = 0;
	int overlap_y2 = 0;

	//가장 큰 x좌표 구하기
	int x_max = 0;
	float cand_x[4] = { rect1_x1 ,rect1_x2 ,rect2_x1 ,rect2_x2 };

	for (i = 0; i < 4; i++) {
		if (cand_x[i] > x_max)
			x_max = cand_x[i];
	}

	//가장 큰 y좌표 구하기
	int y_max = 0;
	float cand_y[4] = { rect1_y1 ,rect1_y2 ,rect2_y1 ,rect2_y2 };

	for (i = 0; i < 4; i++) {
		if (cand_y[i] > y_max)
			y_max = cand_y[i];
	}

	//x_max와 y_max를 크기로 가진 배열 만들기
	int** map = new int*[y_max];
	for (i = 0; i < x_max; ++i)
		map[i] = new int[x_max];

	//전체를 0으로 초기화한다.
	for (i = 0; i < y_max; i++)
		for (j = 0; j < x_max; j++)
			map[i][j] = 0;

	//rect1에 해당하는 배열원소 1씩 증가
	for (i = rect1_y1; i < rect1_y2; i++)
		for (j = rect1_x1; j < rect1_x2; j++)
			map[i][j]++;

	//rect2에 해당하는 배열원소 1씩 증가
	for (i = rect2_y1; i < rect2_y2; i++)
		for (j = rect2_x1; j < rect2_x2; j++)
			map[i][j]++;

	//겹치는 곳 계산(2인 곳들 다 찾기)
	for (i = 0; i < y_max; i++)
		for (j = 0; j < x_max; j++)
			if (map[i][j] == 2) {
				overlaps++;
				if (overlap_x1 == 0 && overlap_y1 == 0) {
					overlap_x1 = j;
					overlap_y1 = i;
				}
				if (j > overlap_x1 && i == overlap_y1) {
					overlap_x2 = j;
					continue;
				}
				if (j > overlap_x1 && i> overlap_y1) {
					overlap_x2 = j;
					overlap_y2 = i;
					continue;
				}
				if (i > overlap_y1 && j == overlap_x1) {
					overlap_y2 = i;
					continue;
				}
			}

	printf("%.1f %.1f %.1f %.1f %.1f\n", rect1_x1, rect1_y1, rect1_x2, rect1_y2, rect1.getArea());
	printf("%.1f %.1f %.1f %.1f %.1f\n", rect2_x1, rect2_y1, rect2_x2, rect2_y2, rect2.getArea());
	if (overlaps == 0) {
		cout << "-1";
	}
	else
		printf("%.1f %.1f %.1f %.1f %.1f\n", (float)(overlap_x1), (float)(overlap_y1), (float)(overlap_x2+1), (float)(overlap_y2+1), (float)overlaps);
}