#include "sphere.h"
#include <iostream>

bool Sphere::Intersect(const Ray& ray, Hit& hit) const {
	Vec3 e = position - ray.origin;
	float rSq = radius * radius;
	float eSq = MagnitudeSq(e);
	float a = Dot(e, ray.direction);
	float bSq = eSq - (a * a);
	float f = sqrt(rSq - bSq);

	//std::cout << rSq - (eSq - (a * a)) << '\n';
	// No collision
	if (rSq - (eSq - (a * a)) < 0.0f) {
		return false;
	}
	// Ray starts inside sphere
	else if (eSq < rSq) {
		hit.point = ray.origin + (a + f);
		return true;
	}
	// Normal intersection
	hit.point = ray.origin + (a - f);
	return true;
};
