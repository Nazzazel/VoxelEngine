#include <string>
#include <unordered_map>


//#include "Engine/Renderer/API/shader.hpp"
#include "Engine/RenderingAPI/Shader/game_shader.hpp"


namespace backends
{



	class OpenGLShader
		: public engine::GameShader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~OpenGLShader();

		OpenGLShader(const OpenGLShader&) = delete;
		OpenGLShader& operator=(const OpenGLShader&) = delete;

		void Bind()		const override;
		void Unbind()	const override;

		//Float
		void SetFloat		(const std::string& name, float value							)override;
		void SetFloat2		(const std::string& name, float x, float y						)override;
		void SetFloat3		(const std::string& name, float x, float y, float z				)override;
		void SetFloat4		(const std::string& name, float x, float y, float z, float w	)override;
		void SetFloatArray	(const std::string& name, float* values, int count				)override;

		//Int
		void SetInt			(const std::string& name, int value						)override;
		void SetInt2		(const std::string& name, int x, int y					)override;
		void SetInt3		(const std::string& name, int x, int y, int z			)override;
		void SetInt4		(const std::string& name, int x, int y, int z, int w	)override;
		void SetIntArray	(const std::string& name, int* values, int count		)override;

		//Unsigned Int
		void SetUInt		(const std::string& name, unsigned int value												)override;
		void SetUInt2		(const std::string& name, unsigned int x, unsigned int y									)override;
		void SetUInt3		(const std::string& name, unsigned int x, unsigned int y, unsigned int z					)override;
		void SetUInt4		(const std::string& name, unsigned int x, unsigned int y, unsigned int z, unsigned int w	)override;
		void SetUIntArray	(const std::string& name, unsigned int* values, int count									)override;


		void SetBool		(const std::string& name, bool value	)override;
		

		void SetMat3		(const std::string& name, const glm::mat3& value	)override;
		void SetMat4		(const std::string& name, const glm::mat4& value	)override;
		
		void SetDouble      (const std::string& name, double value                              )override;
		void SetDouble2     (const std::string& name, double x, double y                        )override;
		void SetDouble3     (const std::string& name, double x, double y, double z              )override;
		void SetDouble4     (const std::string& name, double x, double y, double z, double w    )override;

	private:
		unsigned int m_Program;

		unsigned int CompileShader(unsigned int type, const std::string& source);
		unsigned int CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc);
	
		std::unordered_map<std::string, int> m_UniformCache;

		int GetUniformLocation(const std::string& name);

	
	
	
	};



}