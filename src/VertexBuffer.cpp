
#include "VertexBuffer.hpp"

#define FLOATS_IN_VERTEX 5
#define FLOATS_IN_POSITION 2
#define FLOATS_IN_COLOR 3

VertexBuffer::VertexBuffer() {}
VertexBuffer::VertexBuffer(const void *vertices, uint size) 
: m_size(size)
{

	glGenBuffers(1, &m_vbo);
	BindNewData(vertices, size);

	// Bind data to vao
	glEnableVertexAttribArray(0);  
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, FLOATS_IN_VERTEX * sizeof(float), (void*)0);

	glVertexAttribPointer(1, FLOATS_IN_COLOR, GL_FLOAT, GL_FALSE, FLOATS_IN_VERTEX * sizeof(float), (void*)(FLOATS_IN_POSITION * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}


void VertexBuffer::Bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	glEnableVertexAttribArray(0);  
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, FLOATS_IN_VERTEX * sizeof(float), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, FLOATS_IN_COLOR, GL_FLOAT, GL_FALSE, FLOATS_IN_VERTEX * sizeof(float), (void*)(FLOATS_IN_POSITION * sizeof(float)));

}

void VertexBuffer::BindNewData(const void *vertices, uint size) {
	m_size = size;
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertices, GL_STATIC_DRAW);
}

void VertexBuffer::Unbind() const {
	glBindVertexArray(0);
}

void VertexBuffer::Draw() const {
	glDrawArrays(GL_TRIANGLES, 0, m_size);
}

uint VertexBuffer::GetCount() const {
	return m_size;
}


VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &m_vbo);
}