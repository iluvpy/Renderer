#pragma once

#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "ColorShader.hpp"
#include "types.hpp"


class BufferLayout {
public:
	BufferLayout();
	BufferLayout(const VertexBuffer& vb, const IndexBuffer& ib);
	void init(const VertexBuffer& vb, const IndexBuffer& ib);

	void setColor(const ColorShader& c);
	void setShader(const Shader& _shader);
	void bind();
	void unbind();
	void draw();
	~BufferLayout();
private:
	
	VertexBuffer m_vb;
	IndexBuffer m_ib;
	Shader shader;
	ColorShader color;
	ShaderType shaderType=ShaderType::NONE;

};