#pragma once
#include "types.hpp"
#include "glad/glad.h"
#include <map>
#include <string>


#define U_COLOR_FSH "./shaders/colorFrag.glsl"
#define U_COLOR_VSH "./shaders/colorVert.glsl"

class Shader {

public:
	Shader();
	Shader(const std::string& fragPath, const std::string& vertPath);	
	void init(const std::string& fragPath, const std::string& vertPath);
	void bind();
	void unbind();
	GLuint getProgram();
	GLuint getUniformLocation(const std::string& name);
	~Shader();
private:

	std::string read(const std::string& shaderPath);
	void compile(const std::string& shaderSrc, GLuint shader);

	GLuint program;
};