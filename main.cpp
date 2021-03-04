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
	Sphere sphere1(Point(-1.2f, -1.2f, 15.0f), 0.75f, Color(0, 1, 0));

	// Add the objects to the scene
	scene.Add(sphere);
	scene.Add(sphere1);
	
	// TODO
	if (image.is_open()) {
		image << "P3\n" << WIDTH << ' ' << HEIGHT << "\n255\n";
		for (int j = 0; j < HEIGHT; j++) {
			for (int i = 0; i < WIDTH; i++) {
				Color color = scene.Trace(i, j) * 255.99f;
				image << (int)color.x << ' ' << (int)color.y << ' ' << (int)color.z << '\n';
			}
		}
		image.close();
	}
	return 0;
}
