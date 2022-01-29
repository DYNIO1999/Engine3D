#include "Renderer.h"




void GLClearError(){
    while(glGetError()!= GL_NO_ERROR);
}

bool GLLogCall(const char *function, const char *file, int line){
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << "):" << function << " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}

Renderer::Renderer()
{

}
Renderer::~Renderer()
{

}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr)); // number of INDICES
}

void Renderer::Clear() const{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
}

void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader, unsigned int type) const{
    shader.Bind();
    va.Bind();
    ib.Bind();
    if (type == GL_POINTS){
        GLCall(glDrawElements(GL_POINTS, ib.GetCount(), GL_UNSIGNED_INT, nullptr)); // number of INDICES
    }
    else if (type == GL_TRIANGLES)
    {
        GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
    }
    else if (type == GL_LINES)
    {
        GLCall(glDrawElements(GL_LINES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
    }
}