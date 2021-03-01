#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "object.h"

class Sphere : public Object {
public:
	Point position;
	float radius;
	Color color;

	inline Sphere() : position(Point(0.0f, 0.0f, 0.0f)), radius(1.0f) {}
	inline Sphere(const Point& c, float r, const Color& _color) : position(c), radius(r), color(_color) {}

	bool Intersect(const Ray& ray, Hit& hit) const;
	virtual Color GetColor() const { return color; }
};

#endif