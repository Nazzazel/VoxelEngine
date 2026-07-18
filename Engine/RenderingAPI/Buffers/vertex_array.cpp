#include "vertex_array.hpp"
#include "Backends/API/renderer_api.hpp"
#include "Backends/OpenGL/Buffers/opengl_vertex_array.hpp"

namespace engine
{
	std::unique_ptr<VertexArray> VertexArray::Create()
	{
		backends::RendererAPIType api = backends::RendererAPI::GetAPI();
		//TODO add more cases for other APIs
		switch (api)
		{
		case backends::RendererAPIType::OpenGL:
			return std::make_unique<backends::OpenGLVertexArray>();
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
		return std::unique_ptr<VertexArray>();
	}

}