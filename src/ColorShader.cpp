#include "ColorShader.hpp"


ColorShader::ColorShader(float _r, float _g, float _b, float _a) 
: r(_r/255), g(_g/255), b(_b/255), a(_a/255)
{
	m_shader.init(U_COLOR_FSH, U_COLOR_VSH);
	m_location = m_shader.getUniformLocation("u_Color");
}

void ColorShader::bind() {
	m_shader.bind();
	glUniform4f(m_location, r, g, b, a);
}

void ColorShader::unbind() {
	m_shader.unbind();
}

ColorShader::~ColorShader() {}