
#include "VertexBuffer.hpp"


VertexBuffer::VertexBuffer(const void *vertices, size_t numVertices) 
: numVertices(numVertices)
{
	glGenVertexArrays(1, &vao);  
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*numVertices*3, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);  

	glBindVertexArray(0);
}


void VertexBuffer::bind() {
	glBindVertexArray(vao);
}

void VertexBuffer::unbind() {
	glBindVertexArray(0);
}

void VertexBuffer::draw() {
	glDrawArrays(GL_TRIANGLES, 0, numVertices);
}


VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}