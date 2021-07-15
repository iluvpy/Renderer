#pragma once

#include "glad/glad.h"

/*
3*3 vertex buffer

*/
class VertexBuffer {

public:
	VertexBuffer(const void *vertices);

	void bind();
	void unbind();
	void draw();

	~VertexBuffer(); 

private:

	GLuint vao;
	GLuint vbo;

};