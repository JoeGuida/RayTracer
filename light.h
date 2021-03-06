#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "point.h"
#include "color.h"

typedef struct Light {
	Point position;
	float intensity;
	Color color;

	Light() : position(Vec3(0.0f, 0.0f, 0.0f)), intensity(1.0f), color(Color(1.0f, 1.0f, 1.0f)) {}
	Light(Point p) : position(p), intensity(1.0f), color(Color(1.0f, 1.0f, 1.0f)) {}
	Light(Point p, float i, Color c) : position(p), intensity(i), color(c) {}

} Light;

#endif