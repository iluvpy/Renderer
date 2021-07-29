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
	void bind() const;
	void unbind() const;

	void setShader(const Shader& sh);
	void setShader(const ColorShader& sh);

	inline ColorShader& getColorShader() { return m_colorShader; }
	inline Shader& getShader() { return m_shader; }
	~ShaderHandler();

private:
	ShaderType m_currentShader=ShaderType::NONE;
	ColorShader m_colorShader;
	Shader m_shader;
};