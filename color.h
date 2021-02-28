#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct Color {
	int r;
	int g;
	int b;

	Color() : r(1.0f), g(1.0f), b(1.0f) {}
	Color(int _r, int _g, int _b) : r(_r), g(_g), b(_b) {}
} Color;

#endif