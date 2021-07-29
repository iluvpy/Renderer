#include "BufferHandler.hpp"

BufferHandler::BufferHandler() {}

BufferHandler::BufferHandler(const VertexBuffer& vb, const IndexBuffer& ib, const Shader& sh) {
	m_vb = vb;
	m_ib = ib;
	m_shader.setShader(sh);
}

BufferHandler::BufferHandler(const VertexBuffer& vb, const IndexBuffer& ib, const ColorShader& sh) {
	m_vb = vb;
	m_ib = ib;
	m_shader.setShader(sh);
}

void BufferHandler::bind() const {
	m_shader.bind();
	m_vb.bind();
	m_ib.bind();
}
void BufferHandler::unbind() const {
	m_vb.unbind();
	m_ib.unbind();
	m_shader.unbind();
}

void BufferHandler::setShader(const Shader& _shader) {
	m_shader.setShader(_shader);
}

void BufferHandler::setShader(const ColorShader& _shader) {
	m_shader.setShader(_shader);
}

void BufferHandler::draw() const{
	bind();
	glDrawElements(GL_TRIANGLES, m_ib.getCount(), GL_UNSIGNED_INT, nullptr);
	unbind();
}

BufferHandler::~BufferHandler() {}