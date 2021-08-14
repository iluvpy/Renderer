#include <fstream>
#include <iostream>
#include "Shader.hpp"

Shader::Shader() 
{}

Shader::Shader(const std::string& fragPath, const std::string& vertPath) {
	Init(fragPath, vertPath);
}	

void Shader::Init(const std::string& fragPath, const std::string& vertPath) {
	m_program = glCreateProgram();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	
	std::string fragSrc = read(fragPath);
	std::string vertSrc = read(vertPath);
	compile(vertSrc, vertexShader);
	compile(fragSrc, fragmentShader);

	glAttachShader(m_program, vertexShader);
	glAttachShader(m_program, fragmentShader);
	glLinkProgram(m_program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);  
}

void Shader::Bind() const{
	glUseProgram(m_program);
}

void Shader::Unbind() const{
	glUseProgram(0);
}

std::string Shader::read(const std::string& shaderPath) {
	std::ifstream ifs(shaderPath);
  	std::string content((std::istreambuf_iterator<char>(ifs)),
                       (std::istreambuf_iterator<char>()));
	return content; 
}

void Shader::compile(const std::string& shaderSource, GLuint shader) {
	const char *shaderSrc = shaderSource.c_str();
	glShaderSource(shader, 1, &shaderSrc, NULL);
	glCompileShader(shader);

	int  success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Shader failed to compile:\n" << infoLog << std::endl;
	}
}

GLuint Shader::GetUniformLocation(const std::string& name) {
	auto it = m_locationCache.find(name);
	if (it != m_locationCache.end()) {
		return it->second;
	}
	int location = glGetUniformLocation(m_program, name.c_str());
	m_locationCache[name] = location;
	return location;
}

GLuint Shader::GetProgram() {
	return m_program;
}

void Shader::SetUniform4f(const std::string& name, float f1, float f2, float f3, float f4) {
	Bind();
	glUniform4f(GetUniformLocation(name), f1, f2, f3, f4);
	Unbind();
}

void Shader::SetUniform2f(const std::string& name, float f1, float f2) {
	Bind();
	glUniform2f(GetUniformLocation(name), f1, f2);
	Unbind();
}

void Shader::SetUniformMatrix4f(const std::string& name, glm::mat4 matrix) {
	Bind();
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
	Unbind();
}


Shader::~Shader() {
	glDeleteProgram(m_program);
}