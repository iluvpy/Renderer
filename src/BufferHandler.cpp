#include "BufferHandler.hpp"

BufferHandler::BufferHandler() {}

BufferHandler::BufferHandler(const VertexBuffer& vb, const Shader& sh) {
	m_vb = vb;
	m_shader = sh;
}


void BufferHandler::Bind() const {
	m_shader.Bind();
	m_vb.Bind();
}
void BufferHandler::Unbind() const {
	m_vb.Unbind();
	m_shader.Unbind();
}


void BufferHandler::Draw() const{
	Bind();
	glDrawArrays(GL_TRIANGLES, 0, m_vb.GetCount());
	Unbind();
}

BufferHandler::~BufferHandler() {}