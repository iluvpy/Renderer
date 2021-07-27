#include "ShaderHandler.hpp"


ShaderHandler::ShaderHandler() {}

void ShaderHandler::bind() {
	switch (current_shader)
	{
		case ShaderType::NORMAL:
			shader.bind();
			break;
		case ShaderType::COLOR:
			colorShader.bind();
			break;
		default:
			break;
	}
}

void ShaderHandler::unbind() {
	switch (current_shader)
	{
		case ShaderType::NORMAL:
			shader.unbind();
			break;
		case ShaderType::COLOR:
			colorShader.unbind();
			break;
		default:
			break;
	}
}


void ShaderHandler::setShader(const Shader& sh) {
	current_shader = ShaderType::NORMAL;
	shader = sh;
}

void ShaderHandler::setShader(const ColorShader& sh) {
	current_shader = ShaderType::COLOR;
	colorShader = sh;
}

ShaderHandler::~ShaderHandler() {}