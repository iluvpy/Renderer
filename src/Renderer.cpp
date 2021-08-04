#include "Renderer.hpp"

Renderer::Renderer() {}

void Renderer::AppendDraw(BufferHandler *handler) {
    m_buffers.push_back(handler);
}

void Renderer::Draw()  {
    for (auto handler : m_buffers) {
        handler->Draw();
    }
}

void Renderer::Clear(float r, float g, float b, float a) {
    glClearColor(r/255, g/255, b/255, a/255);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Update() {
}

Renderer::~Renderer() {

}