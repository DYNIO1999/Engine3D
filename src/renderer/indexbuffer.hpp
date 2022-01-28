#ifndef _INDEX_BUFFER_HPP_
#define _INDEX_BUFFER_HPP_

#include "renderer.hpp"

class IndexBuffer
{
private:
    unsigned int m_RendererID; // openGL needs numeric id to track what object is allocated
    unsigned int m_Count;

public:
    IndexBuffer(const unsigned int *data, unsigned int count); // can have different int types, but use 32 for now
    ~IndexBuffer();

    // todo add lock/ unlock, changes while streaming

    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const { return m_Count; }
};
#endif
