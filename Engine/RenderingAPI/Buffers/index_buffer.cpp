#include "index_buffer.hpp"
#include <Backends/API/RendererApi.hpp>
#include <Backends/OpenGL/Buffers/opengl_index_buffer.hpp>

namespace engine
{

    std::unique_ptr<IndexBuffer> engine::IndexBuffer::Create(unsigned int* indices, unsigned int count)
    {
        backends::RendererAPIType api = backends::RendererAPI::GetAPI();
        //TODO add more cases for other APIs

        switch (api)
        {
        case backends::RendererAPIType::OpenGL:
            return std::make_unique<backends::OpenGLIndexBuffer>(indices, count);

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
        return std::unique_ptr<IndexBuffer>();
    }

}