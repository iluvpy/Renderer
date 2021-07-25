#include "ColorShader.hpp"

ColorShader::ColorShader(float r, float g, float b, float a) {
	colorShader.init("./shaders/colorFrag.glsl", "./shaders/colorVert.glsl");
	colorShader.bind();
	setR(r);
	setG(g);
	setB(b);
	setA(a);
	location = colorShader.getUniformLocation("u_Color");
}

void ColorShader::bind() {
	colorShader.bind();
	glUniform4f(location, r, g, b, a);
}
void ColorShader::unbind() {
	colorShader.unbind();
}

void ColorShader::setR(float _r) {
	r = _r/255;
}
void ColorShader::setG(float _g) {
	g = _g/255;
}
void ColorShader::setB(float _b) {
	b = _b/255;
}
void ColorShader::setA(float _a) {
	a = _a/255;
}

ColorShader::~ColorShader() {}