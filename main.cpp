//#include <SDL2/SDL.h>
//#include "window.h"
//
////from the sdl tutorial
////and tweaked
//
//
//int main(int argc, char* argv[]) {
//	photon::win window("apollo drizzle", 640, 480);
//
//	window.fill(Colors::pink);
//
//	for (int i = 10; i < 100; i++) {
//		for (int o = 10; o < 100; o++) {
//			window.set_pixel(i, o, Colors::lightBlue); //set pixel (10, 10) to red
//		}
//	}
//
//	int thickness = 35;
//	for(int i = 0; i < 300; i++) {
//		double v = sin(((double)i)/(3.141565*4))*30;
//		int desired_y = 200 + (int)v;
//		for(int o = desired_y - thickness; o < desired_y + thickness; o++) {
//			Uint8 brightness = (Uint8)(255-(int)((abs((double)(desired_y - o)))/thickness * 255));
//			window.set_pixel(i, o, Colors::yellow);
//		}
//	}
//
//	window.update();
//	window.get_key();
//
//	return 0;
//}
