#ifndef _SCENE_H_
#define _SCENE_H_

#include "object.h"
#include "sphere.h"
#include <vector>

class Scene {
	std::vector<Sphere> spheres;

public:
	Scene() {}
	 
	void Add(const Sphere& sphere) {
		spheres.push_back(sphere);
	}

	Color Trace(int x, int y);
};

#endif