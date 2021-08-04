#include "BufferHandler.hpp"

BufferHandler::BufferHandler() {}

BufferHandler::BufferHandler(const VertexBuffer& vb, const IndexBuffer& ib, const Shader& sh) {
	m_vb = vb;
	m_ib = ib;
	m_shader = sh;
}


void BufferHandler::Bind() const {
	m_shader.Bind();
	m_vb.Bind();
	m_ib.Bind();
}
void BufferHandler::Unbind() const {
	m_vb.Unbind();
	m_ib.Unbind();
	m_shader.Unbind();
}


void BufferHandler::Draw() const{
	Bind();
	glDrawElements(GL_TRIANGLES, m_ib.GetCount(), GL_UNSIGNED_INT, nullptr);
	Unbind();
}

BufferHandler::~BufferHandler() {}