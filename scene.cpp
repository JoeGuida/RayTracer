#include "scene.h"
#include "ray.h"
#include "hit.h"
#include <iostream>

Color Scene::Trace(int x, int y) {
	Ray cameraRay(Point(0.0f, 0.0f, 0.0f), Vec3(x, y, -1.0f));

	for (Sphere sphere : spheres) {
		Hit hit;
		if (sphere.Intersect(cameraRay, hit)) {
			return sphere.GetColor();
		}
	}

	return Color(0, 0, 0);
}
