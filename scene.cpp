#include "scene.h"
#include "ray.h"
#include "hit.h"
#include <iostream>
#include <cmath>

float Diffuse(const Vec3& lightDir, const Vec3& normal) {
	return std::max(0.0f, Dot(normal, -lightDir));
}

float Phong(const Vec3& lightDir, const Vec3& normal, Vec3 e) {
	int p = 256;
	Vec3 r = Reflection(lightDir, normal);
	float angle = std::max(0.0f, Dot(e, r));
	return powf(angle, p);
}

Color Scene::Trace(int u, int v) {
	Ray cameraRay(Point(0.0f, 0.0f, 0.0f), Vec3(u, v, -1000));

	for (const Sphere& sphere : spheres) {
		Hit hit;
		if (sphere.Intersect(cameraRay, hit)) {
			// Light calculations
			float diffuse = 0;
			float phong = 0;
			Color phongColor = Color(0.0f, 0.0f, 0.0f);
			for (const Light& light : lights) {
				Vec3 l = Normalized(hit.point - light.position);
				diffuse = Diffuse(-l, hit.normal);
				phong += Phong(l, hit.normal, cameraRay.direction);
				phongColor += light.color;
			}

			Color color = ambient + (sphere.color * diffuse) + (phongColor * phong);

			// Clamp color values
			color = Color(std::min(1.0f, color.x), std::min(1.0f, color.y), std::min(1.0f, color.z));
			return color;
		}
	}

	return backgroundColor;
}
