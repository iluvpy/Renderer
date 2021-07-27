#pragma once

#include "Shader.hpp"
#include "ColorShader.hpp"

enum ShaderType {
	NORMAL, // shader from "Shader" class
	COLOR, // shader from "ColorShader" class
	TEXTURE, // shader from "TextureShader" class
	NONE // none
};

class ShaderHandler {
public:
	ShaderHandler();
	void bind();
	void unbind();

	void setShader(const Shader& sh);
	void setShader(const ColorShader& sh);

	inline ColorShader& getColorShader() { return colorShader; }
	inline Shader& getShader() { return shader; }
	~ShaderHandler();

private:
	ShaderType current_shader=ShaderType::NONE;
	ColorShader colorShader;
	Shader shader;
};