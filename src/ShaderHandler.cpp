#include "ShaderHandler.hpp"


ShaderHandler::ShaderHandler() {}

void ShaderHandler::bind() const{
	switch (m_currentShader)
	{
		case ShaderType::NORMAL:
			m_shader.bind();
			break;
		case ShaderType::COLOR:
			m_colorShader.bind();
			break;
		default:
			break;
	}
}

void ShaderHandler::unbind() const{
	switch (m_currentShader)
	{
		case ShaderType::NORMAL:
			m_shader.unbind();
			break;
		case ShaderType::COLOR:
			m_colorShader.unbind();
			break;
		default:
			break;
	}
}


void ShaderHandler::setShader(const Shader& sh) {
	m_currentShader = ShaderType::NORMAL;
	m_shader = sh;
}

void ShaderHandler::setShader(const ColorShader& sh) {
	m_currentShader = ShaderType::COLOR;
	m_colorShader = sh;
}

ShaderHandler::~ShaderHandler() {}