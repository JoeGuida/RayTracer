#ifndef _SCENE_H_
#define _SCENE_H_

#include "object.h"
#include "sphere.h"
#include "light.h"
#include <vector>

class Scene {
	float ambient = 0.0f;
	Color backgroundColor = Color(0, 0, 0);

	std::vector<Sphere> spheres;
	std::vector<Light> lights;

public:
	Scene() {}
	 
	void Add(const Sphere& sphere) {
		spheres.push_back(sphere);
	}

	void Add(const Light& light) {
		lights.push_back(light);
	}

	Color Trace(int x, int y);
};

#endif