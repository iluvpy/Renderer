
#include "VertexBuffer.hpp"

#define DIMENSION 2


VertexBuffer::VertexBuffer() {}
VertexBuffer::VertexBuffer(const void *vertices, uint numVertices) 
: m_numVertices(numVertices)
{

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numVertices * DIMENSION, vertices, GL_STATIC_DRAW);

	// Bind data to vao
	glEnableVertexAttribArray(0);  
	glVertexAttribPointer(0, DIMENSION, GL_FLOAT, GL_FALSE, DIMENSION * sizeof(float), (void*)0);

	glBindVertexArray(0);
}


void VertexBuffer::Bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glEnableVertexAttribArray(0);  
	glVertexAttribPointer(0, DIMENSION, GL_FLOAT, GL_FALSE, DIMENSION * sizeof(float), (void*)0);

}

void VertexBuffer::Unbind() const {
	glBindVertexArray(0);
}

void VertexBuffer::Draw() const {
	glDrawArrays(GL_TRIANGLES, 0, m_numVertices);
}

uint VertexBuffer::GetCount() const {
	return m_numVertices;
}


VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &m_vbo);
}