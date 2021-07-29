
#include "VertexBuffer.hpp"

#define DIMENSION 2


VertexBuffer::VertexBuffer() {}
VertexBuffer::VertexBuffer(const void *vertices, uint numVertices) 
: numVertices(numVertices)
{
	glGenVertexArrays(1, &vao);  
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numVertices * DIMENSION, vertices, GL_STATIC_DRAW);

	// bind data to vao
	glEnableVertexAttribArray(0);  
	glVertexAttribPointer(0, DIMENSION, GL_FLOAT, GL_FALSE, DIMENSION * sizeof(float), (void*)0);

	glBindVertexArray(0);
}


void VertexBuffer::bind() const {
	glBindVertexArray(vao);
}

void VertexBuffer::unbind() const {
	glBindVertexArray(0);
}

void VertexBuffer::draw() const {
	glDrawArrays(GL_TRIANGLES, 0, numVertices);
}


VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}