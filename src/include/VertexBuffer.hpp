#pragma once

#include "glad/glad.h"


#include <cstdlib>
class VertexBuffer {

public:
	VertexBuffer();
	VertexBuffer(const void *vertices, uint numVertices);
	void init(const void *vertices, uint numVertices);
	void bind() const;
	void unbind() const;
	void draw() const;

	~VertexBuffer(); 

private:

	GLuint vao;
	GLuint vbo;
	uint numVertices;

};