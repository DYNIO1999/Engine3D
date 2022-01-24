#ifndef _VERTEX_BUFFER_HPP_
#define _VERTEX_BUFFER_HPP_


#include "renderer.hpp"

class VertexBuffer
{
private:
    unsigned int m_RendererID; // openGL needs numeric id to track what object is allocated
public:
    VertexBuffer(const void *data, unsigned int size);
    ~VertexBuffer();

    // todo add lock/ unlock, changes while streaming

    void Bind() const;
    void Unbind() const;
};
#endif