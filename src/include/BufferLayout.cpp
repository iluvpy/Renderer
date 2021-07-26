#include "BufferLayout.hpp"


BufferLayout::BufferLayout() {}

BufferLayout::BufferLayout(const VertexBuffer& vb, const IndexBuffer& ib, const Shader& sh) {
	m_vb = vb;
	m_ib = ib;
	m_shader = sh;
}


void BufferLayout::bind() {
	m_shader.bind();
	m_vb.bind();
	m_ib.bind();
}
void BufferLayout::unbind() {
	m_vb.unbind();
	m_ib.unbind();
	m_shader.unbind();
}

void BufferLayout::setShader(const Shader& _shader) {
	m_shader = _shader;
}

void BufferLayout::draw() {
	bind();
	glDrawElements(GL_TRIANGLES, m_ib.getCount(), GL_UNSIGNED_INT, nullptr);
	unbind();
}

BufferLayout::~BufferLayout() {}