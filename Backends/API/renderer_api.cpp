#include "renderer_api.hpp"

namespace backends
{
    RendererAPIType RendererAPI::s_API = RendererAPIType::OpenGL;

    RendererAPIType RendererAPI::GetAPI()
    {
        return s_API;
    }

    void RendererAPI::SetAPI(RendererAPIType api)
    {
        s_API = api;
    }

    std::string RendererAPI::RendererAPIToString(RendererAPIType api)
    {
        switch (api)
        {
        case RendererAPIType::Default: return "Default";
        case RendererAPIType::OpenGL: return "OpenGL";
        case RendererAPIType::Vulkan: return "Vulkan";
        default: return "Unknown";
        }
    }

}