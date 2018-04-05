#include <SDL2/SDL.h>
#include "window.h"
#include <stdio.h>
#include <math.h>

//from the sdl tutorial
//and tweaked


int main(int argc, char* argv[]) {
	
	
	photon::win window2("apollo drizzle", 640, 480);
	for(int i = 10; i < 100; i++) {
		for(int o = 10; o < 100; o++) {
			window2.set_pixel(i, o, 0, 255, 0); //set pixel (10, 10) to bright green
		}
	}
	int thickness = 70;
	thickness /= 2;
	for(int i = 0; i < 300; i++) {
		double v = sin(((double)i)/(3.141565*4))*30;
		int desired_y = 200 + (int)v;
		for(int o = desired_y - thickness; o < desired_y + thickness; o++) {
			int brightness = 255-(int)((abs((double)(desired_y - o)))/thickness * 255);
			window2.set_pixel(i, o, brightness, brightness, brightness);
		}
	}

	window2.update();
	// Wait a lil, then close window
	window2.get_key();

	return 0;
}
