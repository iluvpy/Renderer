#include "ColorShader.hpp"


ColorShader::ColorShader(float _r, float _g, float _b, float _a) 
: m_r(_r/255), m_g(_g/255), m_b(_b/255), m_a(_a/255)
{
	m_shader.init(U_COLOR_FSH, U_COLOR_VSH);
	m_location = m_shader.getUniformLocation("u_Color");
}

void ColorShader::bind() const{
	m_shader.bind();
	glUniform4f(m_location, m_r, m_g, m_b, m_a);
}

void ColorShader::unbind() const{
	m_shader.unbind();
}

ColorShader::~ColorShader() {}