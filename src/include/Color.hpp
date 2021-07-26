#pragma once

#include "Shader.hpp"

class Color {
public:
	Color(float r=255.0f, float g=255.0f, float b=255.0f, float a=255.0f);
	inline float getR() { return r; }
	inline float getG() { return g; }
	inline float getB() { return b; }
	inline float getA() { return a; }
	inline void setR(float _r) { _r = r; }
	inline void setG(float _g) { _g = g; }
	inline void setB(float _b) { _b = b; }
	inline void setA(float _a) { _a = a; }
private:
	float r, g, b, a;
};