#include "scene.h"
#include "ray.h"
#include "hit.h"
#include <iostream>

Color Scene::Trace(int u, int v) {
	Ray cameraRay(Point(-1.2f, 1.8f, 0.0f), Vec3(u, v, -1000));

	for (Sphere sphere : spheres) {
		Hit hit;
		if (sphere.Intersect(cameraRay, hit)) {
			return sphere.GetColor();
		}
	}

	return Color(0, 0, 0);
}
