#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "object.h"

class Sphere : public Object {
	Point center;
	float radius;
	Color color;

public:
	inline Sphere() : center(Point(0.0f, 0.0f, 0.0f)), radius(1.0f) {}
	inline Sphere(const Point& c, float r, const Color& _color) : center(c), radius(r), color(_color) {}

	bool Intersect(const Ray& ray, Hit& hit) const;
	virtual Color GetColor() const { return color; }
};

#endif