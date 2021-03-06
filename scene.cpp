#include "scene.h"
#include "ray.h"
#include "hit.h"
#include <iostream>
#include <cmath>

bool castRay(const Ray& ray, const Hit& hit, const std::vector<Sphere>& spheres) {
	for (const Sphere& sphere : spheres) {
		Hit hit;
		if (sphere.Intersect(ray, hit)) {
			return true;
		}
	}
	return false;
}

Color Diffuse(const Vec3& lightDir, const Vec3& normal, const Color& surfaceColor) {
	float diffuseValue = std::max(0.0f, Dot(normal, -lightDir));
	return surfaceColor * diffuseValue;
}

Color Phong(const Vec3& lightDir, const Vec3& normal, Vec3 e, const Color& lightColor) {
	int p = 256;
	Vec3 r = Reflection(lightDir, normal);
	float angle = std::max(0.0f, Dot(e, r));
	float phongValue = powf(angle, p);
	return lightColor * phongValue;
}

Color Specular(const Vec3& d, const Hit& hit, const std::vector<Sphere>& spheres) {
	Vec3 r = -Reflection(d, hit.normal);
	Hit rayHit;

	float specularValue = std::max(0.0f, Dot(r, hit.normal));
	Color specularColor = castRay(Ray(hit.point, Normalized(r)), rayHit, spheres);
	return specularColor * specularValue;
}

bool pointInShadow(const Point& hitPoint, const Light& light, const Sphere& surface, const std::vector<Sphere>& spheres) {
	float shadowBias = 0.1f;
	Point origin = hitPoint + shadowBias;
	Ray shadowRay(origin, origin - light.position);
	bool inShadow = false;

	for (const Sphere& sphere : spheres) {
		if (surface.position == sphere.position)
			continue;

		Hit hit;
		if (sphere.Intersect(shadowRay, hit)) {
			inShadow = true;
		}
	}

	return inShadow;
}

Color Scene::Trace(int u, int v) {
	Ray cameraRay(Point(0.0f, 0.0f, 0.0f), Vec3(u, v, -1000));

	for (const Sphere& sphere : spheres) {
		Hit hit;
		if (sphere.Intersect(cameraRay, hit)) {
			Color diffuse(0.0f, 0.0f, 0.0f);
			Color phong(0.0f, 0.0f, 0.0f);
			Color specular(0.0f, 0.0f, 0.0f);

			for (const Light& light : lights) {
				if (pointInShadow(hit.point, light, sphere, spheres))
					return Color(0, 0, 0);
				
				Vec3 l = Normalized(hit.point - light.position);
				diffuse = Diffuse(-l, hit.normal, sphere.color);
				phong = Phong(l, hit.normal, cameraRay.direction, light.color);
				specular = Specular(cameraRay.direction, hit, spheres);
			}
			// Components of color
			Color color = ambient + diffuse + phong + specular;
			
			// Clamp color values before returning
			color = Min(color, 1.0f);
			return color;
		}
	}

	return backgroundColor;
}
