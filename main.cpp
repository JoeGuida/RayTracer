#include "sphere.h"
#include "scene.h"
#include <fstream>
#include <iostream>

int main() {
	// Image dimensions
	const int WIDTH  = 480;
	const int HEIGHT = 360;

	// Create the output image
	std::ofstream image;
	image.open("image.ppm");

	// Create the scene
	Scene scene;

	// Create the objects
	Sphere sphere(Point(-2.4f, -1.8f, 10.0f), 1.0f, Color(0, 0, 1));
	Sphere sphere0(Point(-1.0f, -2.0f, 15.0f), 0.75f, Color(0, 1, 0));
	Sphere sphere1(Point(-6.0f, -1.4f, 20.0f), 1.0f, Color(1, 0, 0));

	// Create the lights
	Light light(Point(-10.0f, 0, 0), 1.0f, Color(1, 1, 1));

	// Add the objects to the scene
	scene.Add(sphere);
	scene.Add(sphere0);
	scene.Add(sphere1);

	// Add the lights to the scene
	scene.Add(light);
	
	// TODO
	if (image.is_open()) {
		image << "P3\n" << WIDTH << ' ' << HEIGHT << "\n255\n";
		for (int i = HEIGHT; i > 0; i--) {
			for (int j = WIDTH; j > 0; j--) {
				Color color = scene.Trace(j, i) * 255.99f;
				image << (int)color.x << ' ' << (int)color.y << ' ' << (int)color.z << '\n';
			}
		}
		image.close();
	}
	return 0;
}
