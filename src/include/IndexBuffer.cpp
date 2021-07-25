
#include "IndexBuffer.hpp"


IndexBuffer::IndexBuffer(uint *indeces, uint count) 
: m_count(count)
{
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(uint), indeces, GL_STATIC_DRAW);
}


void IndexBuffer::bind() const{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
}

void IndexBuffer::unbind() const{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::draw() const {
	glDrawElements(GL_TRIANGLES, m_count, GL_UNSIGNED_INT, nullptr);
}


GLuint IndexBuffer::getCount() const { return m_count; }

IndexBuffer::~IndexBuffer() {
	glDeleteBuffers(1, &ibo);
}