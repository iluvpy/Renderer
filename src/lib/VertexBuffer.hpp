#pragma once

#include "glad/glad.h"

/*
3*3 vertex buffer

*/
#include <cstdlib>
class VertexBuffer {

public:
	VertexBuffer(const void *vertices, size_t numVertices);

	void bind();
	void unbind();
	void draw();

	~VertexBuffer(); 

private:

	GLuint vao;
	GLuint vbo;
	size_t numVertices;

};