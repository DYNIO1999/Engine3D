#include "renderer.hpp"

Renderer::Renderer(){

}
Renderer::~Renderer(){

}
void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const
{
    // bind
    shader.Bind();
    va.Bind();
    ib.Bind();

    // could put this into index buffer
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr)); // number of INDICES

    // TODO: could remove Unbind() here, but its not strictly necessary (wastes performance) but useful for debugging
    shader.Unbind();
    va.Unbind();
    ib.Unbind();
}

void Renderer::Clear() const
{
    // glClearColor(0.2f, 0.3f, 0.3f, 0.5f); // 1 is fully visible alpha
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}
