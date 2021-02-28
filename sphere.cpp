#include "sphere.h"

bool Sphere::Intersect(const Ray& ray, Hit& hit) {
	Vec3 e = center - ray.origin;
	Vec3 a = Project(e, ray.direction);
	Vec3 b = e - Project(e, a);

	// If e is shorter than the radius, the ray is inside the sphere
	if (Magnitude(e) < radius)
		return false;
	// If b is longer than the radius, the ray is not hitting the sphere
	if (Magnitude(b) > radius)
		return false;

	Vec3 fSq = (radius * radius) - (b * b);
	Vec3 f = Vec3(sqrtf(fSq.x), sqrtf(fSq.y), sqrtf(fSq.z));

	// Two possible points
	float t0 = Magnitude(a - f);
	float t1 = Magnitude(a + f);
	
	// Update the hit
	hit.point = ray.origin + t0;

	return true;
};