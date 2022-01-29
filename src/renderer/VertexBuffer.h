#ifndef _VERTEX_BUFFER_H_
#define _VERTEX_BUFFER_H_

class VertexBuffer
{
private:
    unsigned int RendererID;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const ;
};
#endif