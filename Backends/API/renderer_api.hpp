#pragma once
#include <string>


namespace backends
{

    enum class RendererAPIType
    {
        Default,
        OpenGL,
        Vulkan,
		DirectX11, //TODO 
		DirectX12 //TODO 
    };

	class RendererAPI
	{
    public:
        static RendererAPIType GetAPI();
        static void SetAPI(RendererAPIType api);

        static std::string RendererAPIToString(RendererAPIType api);

    private:
        static RendererAPIType s_API;

	};

}