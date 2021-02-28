#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "point.h"
#include "ray.h"
#include "hit.h"

typedef struct Sphere {
	Point center;
	float radius;

	inline Sphere() : radius(1.0f) {}
	inline Sphere(const Point& c, float r) : center(c), radius(r) {}

	bool Intersect(const Ray& ray, Hit& hit);
} Sphere;

#endif