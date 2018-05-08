#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "header.h"

using namespace std;


int main() {

	Rectangle rect[2];
	Overlap overlap;

	for (int i = 0; i < 2; i++) {
		rect[i].input();
	}

	overlap.init(rect[0], rect[1]);
	overlap.overlaprect(rect[0], rect[1]);
	system("pause");
	return 0;
}

