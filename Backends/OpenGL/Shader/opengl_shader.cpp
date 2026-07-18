#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "opengl_shader.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#include "Backends/OpenGL/Debug/GLScope.hpp"

namespace backends
{
	OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		GL_SCOPE();
		m_Program = CreateShader(vertexSrc, fragmentSrc);
	}
	OpenGLShader::~OpenGLShader()
	{
		GL_SCOPE();
		glDeleteProgram(m_Program);
	}
	void OpenGLShader::Bind() const
	{
		GL_SCOPE();
		glUseProgram(m_Program);
	}
	void OpenGLShader::Unbind() const
	{
		GL_SCOPE();
		glUseProgram(0);
	}



	unsigned int OpenGLShader::CompileShader(unsigned int type, const std::string& source)
	{
		GL_SCOPE(); 

		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);
		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			std::cout << "Failed to compile "
				<< (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
				<< " shader!" << std::endl;
			std::cout << message << std::endl;
			glDeleteShader(id);
			return 0;
		}
		return id;
		//return 0; //TODO
	}

	unsigned int OpenGLShader::CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		GL_SCOPE();
		//std::cout << "//// DEV //// \n CreateShader\n " << vertexSrc << std::endl;
		//std::cout << "//// DEV //// \n CreateShader\n " << fragmentSrc << std::endl;


		//std::string vertexShaderSource		= ParseShader(vertexSrc		);
		////std::string fragmentShaderSource	= ParseShader(fragmentSrc	);


		////std::cout << vertexShaderSource << std::endl;

		unsigned int program = glCreateProgram();
		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexSrc);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);
		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);
		glDeleteShader(vs);
		glDeleteShader(fs);
		return program;
		return 0; //TODO
	}

	int OpenGLShader::GetUniformLocation(const std::string& name)
	{
		GL_SCOPE();//DEBUGGIN //TODO IF YOU NEED 
		// 1. Check cache first
		if (m_UniformCache.find(name) != m_UniformCache.end())
			return m_UniformCache[name];

		// 2. Ask OpenGL only if not cached
		int location = glGetUniformLocation(m_Program, name.c_str());

		// 3. Store result (even if -1, cache it!)
		m_UniformCache[name] = location;

		return location;
	}


	void OpenGLShader::SetFloat		(const std::string& name, float value)							{ GL_SCOPE(); glUniform1f(GetUniformLocation(name), value		); }
	void OpenGLShader::SetFloat2	(const std::string& name, float x, float y)						{ GL_SCOPE(); glUniform2f(GetUniformLocation(name), x, y		); }
	void OpenGLShader::SetFloat3	(const std::string& name, float x, float y, float z)			{ GL_SCOPE(); glUniform3f(GetUniformLocation(name), x, y, z		); }
	void OpenGLShader::SetFloat4	(const std::string& name, float x, float y, float z, float w)	{ GL_SCOPE(); glUniform4f(GetUniformLocation(name), x, y, z, w	); }

	void OpenGLShader::SetFloatArray(const std::string& name, float* values, int count)				{ GL_SCOPE(); glUniform1fv(GetUniformLocation(name), count, values);}


	void OpenGLShader::SetInt		(const std::string& name, int value)							{ GL_SCOPE(); glUniform1i(GetUniformLocation(name), value		); }
	void OpenGLShader::SetInt2		(const std::string& name, int x, int y)							{ GL_SCOPE(); glUniform2i(GetUniformLocation(name), x, y		); }
	void OpenGLShader::SetInt3		(const std::string& name, int x, int y, int z)					{ GL_SCOPE(); glUniform3i(GetUniformLocation(name), x, y, z		); }
	void OpenGLShader::SetInt4		(const std::string& name, int x, int y, int z, int w)			{ GL_SCOPE(); glUniform4i(GetUniformLocation(name), x, y, z, w	); }

	void OpenGLShader::SetIntArray	(const std::string& name, int* values, int count)				{ GL_SCOPE(); glUniform1iv(GetUniformLocation(name), count, values); }



	void OpenGLShader::SetUInt		(const std::string& name, unsigned int value)												{ GL_SCOPE(); glUniform1ui(GetUniformLocation(name), value		); }
	void OpenGLShader::SetUInt2		(const std::string& name, unsigned int x, unsigned int y)									{ GL_SCOPE(); glUniform2ui(GetUniformLocation(name), x, y		); }
	void OpenGLShader::SetUInt3		(const std::string& name, unsigned int x, unsigned int y, unsigned int z)					{ GL_SCOPE(); glUniform3ui(GetUniformLocation(name), x, y, z	); }
	void OpenGLShader::SetUInt4		(const std::string& name, unsigned int x, unsigned int y, unsigned int z, unsigned int w)	{ GL_SCOPE(); glUniform4ui(GetUniformLocation(name), x, y, z, w	); }
	
	void OpenGLShader::SetUIntArray	(const std::string& name, unsigned int* values, int count)									{ GL_SCOPE(); glUniform1uiv(GetUniformLocation(name), count, values); }


	void OpenGLShader::SetBool(const std::string& name, bool value)		{ GL_SCOPE(); glUniform1i(GetUniformLocation(name), (int)value);}


	void OpenGLShader::SetMat3(const std::string& name, const glm::mat3& value) { GL_SCOPE(); glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]); }
	void OpenGLShader::SetMat4(const std::string& name, const glm::mat4& value) { GL_SCOPE(); glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]); }


	void OpenGLShader::SetDouble(const std::string& name, double value)								{ GL_SCOPE(); glUniform1d(GetUniformLocation(name), value		); }
	void OpenGLShader::SetDouble2(const std::string& name, double x, double y)						{ GL_SCOPE(); glUniform2d(GetUniformLocation(name), x, y		); }
	void OpenGLShader::SetDouble3(const std::string& name, double x, double y, double z)			{ GL_SCOPE(); glUniform3d(GetUniformLocation(name), x, y, z		); }
	void OpenGLShader::SetDouble4(const std::string& name, double x, double y, double z, double w)	{ GL_SCOPE(); glUniform4d(GetUniformLocation(name), x, y, z, w	); }

}