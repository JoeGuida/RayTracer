#ifndef _RAY_H_
#define _RAY_H_

#include "point.h"

typedef struct Ray {
	Point origin;
	Vec3 direction;

	inline Ray() : origin(0.0f, 0.0f, 0.0f), direction(0.0f, 0.0f, 1.0f) {}
	inline Ray(const Point& o, const Vec3& d) : origin(o), direction(d) { NormalizeDirection(); }
	inline void NormalizeDirection() { Normalize(direction); }
} Ray;

#endif