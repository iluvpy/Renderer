#include "Color.hpp"

Color::Color(float r, float g, float b, float a) {
	colorShader.init("./shaders/colorFrag.glsl", "./shaders/colorVert.glsl");
	colorShader.bind();
	setR(r);
	setG(g);
	setB(b);
	setA(a);
	location = glGetUniformLocation(colorShader.getProgram(), "u_Color");
}

void Color::bind() {
	colorShader.bind();
	glUniform4f(location, r, g, b, a);
}
void Color::unbind() {
	colorShader.unbind();
}

void Color::setR(float _r) {
	r = _r/255;
}
void Color::setG(float _g) {
	g = _g/255;
}
void Color::setB(float _b) {
	b = _b/255;
}
void Color::setA(float _a) {
	a = _a/255;
}

Color::~Color() {}