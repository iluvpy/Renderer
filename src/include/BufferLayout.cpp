#include "BufferLayout.hpp"


BufferLayout::BufferLayout() {}

BufferLayout::BufferLayout(const VertexBuffer& vb, const IndexBuffer& ib) {
	init(vb, ib);
}

void BufferLayout::init(const VertexBuffer& vb, const IndexBuffer& ib) {
	m_vb = vb;
	m_ib = ib;
}

void BufferLayout::bind() {
	if (shaderType == ShaderType::SHADER) shader.bind();
	else if (shaderType == ShaderType::COLOR) color.bind();
	m_vb.bind();
	m_ib.bind();
}
void BufferLayout::unbind() {
	m_vb.unbind();
	m_ib.unbind();
	if (shaderType == ShaderType::SHADER) shader.unbind();
	else if (shaderType == ShaderType::COLOR) color.unbind();
}

void BufferLayout::draw() {
	bind();
	glDrawElements(GL_TRIANGLES, m_ib.getCount(), GL_UNSIGNED_INT, nullptr);
	unbind();
}

void BufferLayout::setShader(const Shader& _shader) { 
	shader = _shader; 
	shaderType = ShaderType::SHADER;
}
void BufferLayout::setColor(const ColorShader& c) { 
	color = c; 
	shaderType = ShaderType::COLOR;
}

BufferLayout::~BufferLayout() {}