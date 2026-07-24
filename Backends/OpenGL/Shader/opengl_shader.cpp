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
	OpenGLShader::OpenGLShader(std::vector<engine::ShaderData>& sources)
	{
		GL_SCOPE();
		m_Program = CreateShader(sources);

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





	unsigned int OpenGLShader::CreateShader(std::vector<engine::ShaderData>& sources)
	{
		GL_SCOPE();
		//std::cout << "//// DEV //// \n CreateShader\n " << vertexSrc << std::endl;
		//std::cout << "//// DEV //// \n CreateShader\n " << fragmentSrc << std::endl;


		//std::string vertexShaderSource		= ParseShader(vertexSrc		);
		////std::string fragmentShaderSource	= ParseShader(fragmentSrc	);


		////std::cout << vertexShaderSource << std::endl;
		///
		///
		///
		//sources.

		unsigned int program = glCreateProgram();
		unsigned int shader_type;

		std::vector<unsigned int> shader_ids;

		for (auto& data : sources)
		{
			//std::cout << "ffffffff: " << ShaderStageToString(data.stage) << "\n";
			//std::cout << "ffffffff: " << "\n";
			//std::cout << "hhhgdfghfdfghhg: " << "\n";


			std::cout << "ShaderStage: " << ShaderStageToString(data.stage) << "\n";

			switch (data.stage)
			{
				case engine::ShaderStage::Vertex:					{ shader_type = GL_VERTEX_SHADER; break;}
				case engine::ShaderStage::TessellationControl:		{ shader_type = GL_TESS_CONTROL_SHADER; break;}
				case engine::ShaderStage::TessellationEvaluation:	{ shader_type = GL_TESS_EVALUATION_SHADER; break;}
				case engine::ShaderStage::Geometry:					{ shader_type = GL_GEOMETRY_SHADER; break;}
				case engine::ShaderStage::Fragment:					{ shader_type = GL_FRAGMENT_SHADER; break;}

				case engine::ShaderStage::Compute:					{ shader_type = GL_COMPUTE_SHADER; break;}
			}

			unsigned int shader = CompileShader(shader_type	, data.shaderSource);
			if (shader){shader_ids.push_back(shader);}


				//std::cout << "ffffffff: " << "\n";


			//std::vector<engine::ShaderStage> stages;
			//stages.emplace_back(data);


			// Assuming ShaderData has a way to check its stage and get its source string/content
		//	if (data.stage == engine::ShaderStage::Vertex)
		//	{
		//		//vertexSrc = data.Source; // or data.GetSource()
		//	}
		//	else if (data.Stage == engine::ShaderStage::Fragment)
		//	{
		//		//fragmentSrc = data.Source;
		//	}
		}
		//

		if (sources.size() == shader_ids.size())
		{

			std::cout << "ddddd: " << "\n";

			for (auto& compiled_data : shader_ids)
			{
				glAttachShader(program, compiled_data);
			}

			glLinkProgram(program);
			glValidateProgram(program);

			for (auto& compiled_data : shader_ids)
			{
				glDeleteShader(compiled_data);
			}

			//glAttachShader(program, vs);
			////glAttachShader(program, fs);
			//glLinkProgram(program);
			//glValidateProgram(program);
			//glDeleteShader(vs);
			//glDeleteShader(fs);
			return program;


		}

		return 0; //TODO
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