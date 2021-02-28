#include <fstream>

int main() {
	// Image dimensions
	const int WIDTH  = 480;
	const int HEIGHT = 360;

	// Create the output image
	std::ofstream image;
	image.open("image.ppm");

	if (image.is_open()) {
		image << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {

			}
		}
	}
	return 0;
}