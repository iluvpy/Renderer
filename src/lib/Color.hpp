#pragma once

#include <glm/glm.hpp>
#include "Shader.hpp"

class Color {
public:
	Color(uint8_t r=0, uint8_t g=0, uint8_t b=0, uint8_t a=255);
	void bind();
	void unbind();
	~Color();
private:

	glm::vec4 toRGB(float r, float g, float b, float a);
	glm::vec4 color;
	Shader colorShader;
	int location;
};