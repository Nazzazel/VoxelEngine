#pragma once
#include <string>

namespace engine
{
	class ShaderLoader
	{
	public:
		ShaderLoader() = default;
		~ShaderLoader() = default;
		std::string OpenGLShaderLoader(const std::string& filepath);

	private:
	};
}