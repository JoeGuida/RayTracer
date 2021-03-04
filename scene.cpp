#include "scene.h"
#include "ray.h"
#include "hit.h"
#include <iostream>
#include <cmath>

float Diffuse(const Vec3& lightDir, const Vec3& normal) {
	float angle = std::max(0.0f, Dot(normal, -lightDir));
	return cos(angle);
}

Color Scene::Trace(int u, int v) {
	Ray cameraRay(Point(0.0f, 0.0f, 0.0f), Vec3(u, v, -1000));

	for (Sphere sphere : spheres) {
		Hit hit;
		if (sphere.Intersect(cameraRay, hit)) {
			float diffuse = Diffuse(cameraRay.direction, hit.normal);

			return sphere.GetColor() * diffuse;
		}
	}

	return Color(0, 0, 0);
}
