#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "point.h"

typedef struct Light {
	Point position;
	float intensity;

	Light() : position(Vec3(0.0f, 0.0f, 0.0f)), intensity(1.0f) {}
	Light(Point p) : position(p), intensity(1.0f) {}
	Light(Point p, float i) : position(p), intensity(i) {}

} Light;

#endif