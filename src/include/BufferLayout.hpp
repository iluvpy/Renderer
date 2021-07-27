#pragma once

#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "ColorShader.hpp"
#include "ShaderHandler.hpp"
#include "types.hpp"


class BufferLayout {
public:
	BufferLayout();
	BufferLayout(const VertexBuffer& vb, const IndexBuffer& ib, const Shader& sh);
	BufferLayout(const VertexBuffer& vb, const IndexBuffer& ib, const ColorShader& sh);
	void bind();
	void unbind();
	void draw();
	void setShader(const Shader& _shader);
	void setShader(const ColorShader& _shader);
	inline ShaderHandler& getShader() {return m_shader;}
	~BufferLayout();
private:

	VertexBuffer m_vb;
	IndexBuffer m_ib;
	ShaderHandler m_shader;
};