#pragma once

#include "Shader.hpp"

class ColorShader {
public:
	ColorShader(float r=255.0f, float g=255.0f, float b=255.0f, float a=255.0f);
	void bind();
	void unbind();
	void setR(float _r);
	void setG(float _g);
	void setB(float _b);
	void setA(float _a);
	inline const Shader& getShader() { return colorShader; }
	inline const GLuint getShaderProgram() { return colorShader.getProgram(); }
	~ColorShader();
private:

	void from255to1(float r, float g, float b, float a);
	float r, g, b, a;
	Shader colorShader;
	int location;
};