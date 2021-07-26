#pragma once

#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "ColorShader.hpp"
#include "Color.hpp"
#include "types.hpp"


class BufferLayout {
public:
	BufferLayout();
	BufferLayout(const VertexBuffer& vb, const IndexBuffer& ib, const Shader& sh);

	void setShader(const Shader& _shader);
	void bind();
	void unbind();
	void draw();
	~BufferLayout();
private:

	VertexBuffer m_vb;
	IndexBuffer m_ib;
	Shader m_shader;
};