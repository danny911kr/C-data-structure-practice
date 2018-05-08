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

	//���� ū x��ǥ ���ϱ�
	int x_max = 0;
	float cand_x[4] = { rect1_x1 ,rect1_x2 ,rect2_x1 ,rect2_x2 };

	for (i = 0; i < 4; i++) {
		if (cand_x[i] > x_max)
			x_max = cand_x[i];
	}

	//���� ū y��ǥ ���ϱ�
	int y_max = 0;
	float cand_y[4] = { rect1_y1 ,rect1_y2 ,rect2_y1 ,rect2_y2 };

	for (i = 0; i < 4; i++) {
		if (cand_y[i] > y_max)
			y_max = cand_y[i];
	}

	//x_max�� y_max�� ũ��� ���� �迭 �����
	int** map = new int*[y_max];
	for (i = 0; i < x_max; ++i)
		map[i] = new int[x_max];

	//��ü�� 0���� �ʱ�ȭ�Ѵ�.
	for (i = 0; i < y_max; i++)
		for (j = 0; j < x_max; j++)
			map[i][j] = 0;

	//rect1�� �ش��ϴ� �迭���� 1�� ����
	for (i = rect1_y1; i < rect1_y2; i++)
		for (j = rect1_x1; j < rect1_x2; j++)
			map[i][j]++;

	//rect2�� �ش��ϴ� �迭���� 1�� ����
	for (i = rect2_y1; i < rect2_y2; i++)
		for (j = rect2_x1; j < rect2_x2; j++)
			map[i][j]++;

	//��ġ�� �� ���(2�� ���� �� ã��)
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