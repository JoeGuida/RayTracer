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
	Sphere sphere(Point(0.f, 0.f, -5.0f), 1.0f, Color(0, 0, 255));

	// Add the objects to the scene
	scene.Add(sphere);
	
	// TODO
	if (image.is_open()) {
		image << "P3\n" << WIDTH << ' ' << HEIGHT << "\n255\n";
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				Color color = scene.Trace(x, y);
				image << color.r << ' ' << color.g << ' ' << color.b << '\n';
			}
		}
		image.close();
	}
	return 0;
}
