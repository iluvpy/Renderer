#pragma once

#include "Shader.hpp"
#include "Color.hpp"

class ColorShader : public Shader {
public:
	ColorShader();
	ColorShader(const Color& c);
	
	~ColorShader();
private:

	Color c;
};