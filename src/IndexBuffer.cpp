
#include "IndexBuffer.hpp"

IndexBuffer::IndexBuffer() {}
IndexBuffer::IndexBuffer(uint *indices, uint count) 
: m_count(count)
{
	glGenBuffers(1, &m_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(uint), indices, GL_STATIC_DRAW);
}


void IndexBuffer::Bind() const{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
}

void IndexBuffer::Unbind() const{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::Draw() const {
	glDrawElements(GL_TRIANGLES, m_count, GL_UNSIGNED_INT, nullptr);
}


IndexBuffer::~IndexBuffer() {
	glDeleteBuffers(1, &m_ibo);
}