#pragma once
#include <glad/glad.h>
#include <string>

class Shader {

public:
	Shader(const std::string& fragPath, const std::string& vertPath);	

	void bind();
	void unbind();
	~Shader();
private:

	std::string read(const std::string& shaderPath);
	void compile(const std::string& shaderSrc, GLuint shader);

	GLuint program;
	GLuint vertexShader;
	GLuint fragmentShader;

};