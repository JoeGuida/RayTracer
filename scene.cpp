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

bool isInShadow(const Ray& ray, std::vector<Sphere> spheres, const Sphere& surface) {
	for (const Sphere& sphere : spheres) {
		if (surface.position == sphere.position)
			continue;

		Hit hit;
		if (sphere.Intersect(ray, hit)) {
			return true;
		}
	}
	return false;
}

Color Scene::Trace(int u, int v) {
	Ray cameraRay(Point(0.0f, 0.0f, 0.0f), Vec3(u, v, -1000));

	for (const Sphere& sphere : spheres) {
		Hit hit;
		if (sphere.Intersect(cameraRay, hit)) {
			float diffuse = 0; 
			float phong = 0;
			Color lightColor = Color(0.0f, 0.0f, 0.0f);

			for (const Light& light : lights) {
				// Shadows
				float shadowBias = 0.1f;
				Point origin = hit.point + shadowBias;
				Ray shadowRay(origin, origin - light.position);
				if (isInShadow(shadowRay, spheres, sphere)) {
					return Min(ambient + Color(0, 0, 0), 1.0f);
				}

				Vec3 l = Normalized(hit.point - light.position);
				diffuse = Diffuse(-l, hit.normal);
				phong += Phong(l, hit.normal, cameraRay.direction);
				lightColor += light.color;
			}

			// Components of color
			Color diffuseColor = sphere.color * diffuse;
			Color phongColor = lightColor * phong;
			Color color = ambient + diffuseColor + phongColor;

			// Clamp color values before returning
			color = Min(color, 1.0f);
			return color;
		}
	}

	return backgroundColor;
}
