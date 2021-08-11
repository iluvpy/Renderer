#include "Renderer.hpp"

Renderer::Renderer(float width, float height) {
    float w = 400.0f;
	float h = 400.0f;
	float x = width/2.0f-w/2.0f;
	float y = height/2.0f-h/2.0f;
	uint numVertices = 30;
	float vertices[] = {
		x,   y,     1.0f, 0.0f, 0.0f,
		x+w, y,     0.0f, 1.0f, 0.0f, 
		x, 	 y+h, 	0.0f, 0.0f, 1.0f,

		x,   y+h, 	0.0f, 0.0f, 1.0f,
		x+w, y+h, 	1.0f, 0.0f, 0.0f,
		x+w, y,    	0.0f, 1.0f, 0.0f
	};  


	glm::mat4 ortho = glm::ortho(0.0f, width, height, 0.0f);

	m_buf = VertexBuffer(vertices, numVertices);
	
	m_shader.Init(BASIC_FS, BASIC_VS);
	m_shader.SetUniformMatrix4f("u_Proj", ortho);
}


void Renderer::Update()  {
    m_shader.Bind();
    m_buf.Bind();
    glDrawArrays(GL_TRIANGLES, 0, m_buf.GetCount());
    m_shader.Unbind();
    m_buf.Unbind();
    //m_data.clear();
}

void Renderer::Clear(float r, float g, float b, float a) {

    // size_t data_size = m_data.size();

    // float data[data_size];
    // for (int i = 0; i < data_size; i++) {
    //     data[i] = m_data[i];
    // }

    // m_buf.GetBuffer()->BindNewData(data, data_size);

    glClearColor(r/255, g/255, b/255, a/255);
    glClear(GL_COLOR_BUFFER_BIT);
}


void Renderer::DrawRect(const Rect& rect) {
    for (float pos : rect.GetAsVertexBufferData()) {
        m_data.push_back(pos);
    }
}

Renderer::~Renderer() {

}