#pragma once
#include "types.hpp"
#include "glad/glad.h"

#include <string>
#include <unordered_map>

#define BASIC_FS "./shaders/basicFs.glsl"
#define BASIC_VS "./shaders/basicVs.glsl"

class Shader {

public:
	Shader();
	Shader(const std::string& fragPath, const std::string& vertPath);	
	void init(const std::string& fragPath, const std::string& vertPath);
	void bind() const;
	void unbind() const;
	GLuint getProgram();
	GLuint getUniformLocation(const std::string& name);
	void SetUniform4f(const std::string& name, float f1, float f2, float f3, float f4);
	~Shader();
private:

	std::string read(const std::string& shaderPath);
	void compile(const std::string& shaderSrc, GLuint shader);

	std::unordered_map<std::string, int> m_locationCache;
	GLuint m_program;
};