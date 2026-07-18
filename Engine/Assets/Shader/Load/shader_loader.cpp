#include "shader_loader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

namespace engine
{

		

	std::string ShaderLoader::OpenGLShaderLoader(const std::string& filepath)
	{
		std::ifstream stream(filepath);

		if (!stream.is_open())
		{
		    std::cerr << "File could not be opened\n";
		    return "";
		}

		 std::stringstream ss;
		 ss << stream.rdbuf();

		return ss.str();
		//return ""; //TODO
	}

}