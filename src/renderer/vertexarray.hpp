#ifndef _VERTEX_ARRAY_HPP_
#define _VERTEX_ARRAY_HPP_

#include "vertexbuffer.hpp"
#include "vertexbufferlayout.hpp"

class VertexArray{

private:
    unsigned int m_RendererId;
public:
    VertexArray();
    ~VertexArray();

    void AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout);
    void Bind() const;
    void Unbind() const;
};
#endif