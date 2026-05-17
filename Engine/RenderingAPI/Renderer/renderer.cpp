#include "RenderingAPI/Renderer/renderer.hpp"
#include "Backends/OpenGL/Renderer/opengl_renderer.hpp"
#include <Backends/API/renderer_api.hpp>
#include <iostream>


namespace engine
{

    std::unique_ptr<Renderer> Renderer::Create()
    {
		backends::RendererAPIType type = backends::RendererAPI::GetAPI();
        switch (type)
        {
		    case backends::RendererAPIType::OpenGL:
		    	return std::make_unique<backends::OpenGLRenderer>();

            case backends::RendererAPIType::Vulkan:
                break;
                //return new OpenGLRenderer();

            case backends::RendererAPIType::DirectX11:
				break;
                //return new OpenGLRenderer();

			case backends::RendererAPIType::Default:
                break;

            default:
                break;
        }
       
        // TODO cabability of chaniging the Renderer for now OpenGL
        std::cout << "GL GL" << std::endl;
		return nullptr; //TODO
    }
}