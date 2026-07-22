#include "vertex_buffer.hpp"
#include "Backends/API/RendererApi.hpp"
#include "Backends/OpenGL/Buffers/opengl_vertex_buffer.hpp"

namespace engine
{

    std::unique_ptr<VertexBuffer> engine::VertexBuffer::Create(const void* data, unsigned int size)
    {
		backends::RendererAPIType api = backends::RendererAPI::GetAPI();
		//TODO add more cases for other APIs

		switch (api)
		{
        case backends::RendererAPIType::OpenGL:
            return std::make_unique<backends::OpenGLVertexBuffer>(data,size);

        case backends::RendererAPIType::Vulkan:
            break;
            //TODO
           

        case backends::RendererAPIType::DirectX11:
            break;
           //TODO

        case backends::RendererAPIType::Default:
            break;

            //TODO

        default:
            break;
            //TODO
        }
        return std::unique_ptr<VertexBuffer>();
    }

}