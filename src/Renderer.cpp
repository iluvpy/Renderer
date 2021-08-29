#include "Renderer.hpp"


Renderer::Renderer(Shader *shader, VertexBuffer *buf) 
: m_buf(buf), m_shader(shader)
{}


void Renderer::Update()  {

	// copies data into gpu
    m_buf->BindNewData(&m_data[0], m_data.size());
    // free old data
    m_data.clear();

    m_shader->Bind();
    m_buf->Bind();
    glDrawArrays(GL_TRIANGLES, 0, m_buf->GetCount());
    m_shader->Unbind();
    m_buf->Unbind();

    
    
}

void Renderer::Clear(float r, float g, float b, float a) {
    glClearColor(r/255, g/255, b/255, a/255);
    glClear(GL_COLOR_BUFFER_BIT);
 
}


void Renderer::DrawRect(const Rect& rect) {
    for (float f : rect.GetAsVertexBufferData()) {
        m_data.push_back(f);
    }
}

void Renderer::DrawTriangle(const Triangle& triangle) {
    for (float f : triangle.GetAsVertexBufferData()) {
        m_data.push_back(f);
    }
}

void Renderer::DrawVertex(float x, float y, const Color& color) {
    m_data.push_back(x);
    m_data.push_back(y);
    m_data.push_back(color.GetR());
    m_data.push_back(color.GetG());
    m_data.push_back(color.GetB());
}

// creates a simple vertex buffer for the renderer 
// note this function needs to be called in the main function
VertexBuffer Renderer::GenerateRenderingBuffer() {
	uint numVertices = 5;
	float vertices[] = {
		0.0f, 0.0f, 0.0f, 0.0f, 0.0f
	};  
    return VertexBuffer(vertices, numVertices);
}

// creates a basic shader predefined for the renderer
// note this function needs to be called in the main function 
Shader Renderer::GenerateRenderingShader(float window_width, float window_height) {
    glm::mat4 ortho = glm::ortho(0.0f, window_width, window_height, 0.0f);
	Shader sh;
	sh.Init(BASIC_FS, BASIC_VS);
	sh.SetUniformMatrix4f("u_Proj", ortho);
    return sh;
}


Renderer::~Renderer() {

}