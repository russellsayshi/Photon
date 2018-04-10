#ifndef PHOTON_COLORS_H
#define PHOTON_COLORS_H
#include <tuple>

using std::make_tuple;

class Colors {
public:
	typedef std::tuple<Uint8, Uint8, Uint8> color;

	constexpr static color red = make_tuple((Uint8)255, (Uint8)0, (Uint8)0);
	constexpr static color orange = make_tuple((Uint8)255, (Uint8)128, (Uint8)0);
	constexpr static color yellow = make_tuple((Uint8)255, (Uint8)255, (Uint8)0);
	constexpr static color green = make_tuple((Uint8)0, (Uint8)255, (Uint8)0);
	constexpr static color lightBlue = make_tuple((Uint8)0, (Uint8)255, (Uint8)255);
	constexpr static color blue = make_tuple((Uint8)0, (Uint8)128, (Uint8)255);
	constexpr static color purple = make_tuple((Uint8)128, (Uint8)0, (Uint8)255);
	constexpr static color pink = make_tuple((Uint8)255, (Uint8)0, (Uint8)128);
	constexpr static color white = make_tuple((Uint8)255, (Uint8)255, (Uint8)255);
	constexpr static color black = make_tuple((Uint8)0, (Uint8)0, (Uint8)0);
};


#endif //PHOTON_COLORS_H
