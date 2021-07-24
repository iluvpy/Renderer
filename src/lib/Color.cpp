#include "Color.hpp"

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	colorShader.init("./shaders/colorFrag.glsl", "./shaders/colorVert.glsl");
	colorShader.bind();
	color = toRGB(r, g, b, a);
	location = glGetUniformLocation(colorShader.getProgram(), "u_Color");
}

void Color::bind() {
	colorShader.bind();
	glUniform4f(location, color.r, color.g, color.b, color.a);
}
void Color::unbind() {
	colorShader.unbind();
}

glm::vec4 Color::toRGB(float r, float g, float b, float a) {
	return glm::vec4(r/255, g/255, b/255, a/255);
}

Color::~Color() {

}