#pragma once

#include "Shader.hpp"

class Color {
public:
	Color(float r=0, float g=0, float b=0, float a=255);
	void bind();
	void unbind();
	void setR(float _r);
	void setG(float _g);
	void setB(float _b);
	void setA(float _a);

	~Color();
private:

	void from255to1(float r, float g, float b, float a);
	float r, g, b, a;
	Shader colorShader;
	int location;
};