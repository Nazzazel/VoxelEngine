#pragma once

//#include "Engine/Assets/Shader/ShaderManager/Core/ShaderTypeID.h"

#include <memory>
#include <string>
#include <glm/glm.hpp>

namespace engine
{
    class GameShader
    {
    public:

        virtual ~GameShader() = default;

		virtual void Bind()     const  = 0;
		virtual void Unbind()   const = 0;


        //Float
        virtual void SetFloat       (const std::string& name, float value                           ) = 0;
        virtual void SetFloat2      (const std::string& name, float x, float y                      ) = 0;
        virtual void SetFloat3      (const std::string& name, float x, float y, float z             ) = 0;
        virtual void SetFloat4      (const std::string& name, float x, float y, float z, float w    ) = 0;
        virtual void SetFloatArray  (const std::string& name, float* values, int count              ) = 0;


        //Int
        virtual void SetInt         (const std::string& name, int value                             ) = 0;
        virtual void SetInt2        (const std::string& name, int x, int y                          ) = 0;
        virtual void SetInt3        (const std::string& name, int x, int y, int z                   ) = 0;
        virtual void SetInt4        (const std::string& name, int x, int y, int z, int w            ) = 0;
        virtual void SetIntArray    (const std::string& name, int* values, int count                ) = 0;
        

        //Unsigned Int
        virtual void SetUInt        (const std::string& name, unsigned int value                                                        ) = 0;
        virtual void SetUInt2       (const std::string& name, unsigned int x, unsigned int y                                            ) = 0;
        virtual void SetUInt3       (const std::string& name, unsigned int x, unsigned int y, unsigned int z                            ) = 0;
        virtual void SetUInt4       (const std::string& name, unsigned int x, unsigned int y, unsigned int z, unsigned int w            ) = 0;
        virtual void SetUIntArray   (const std::string& name, unsigned int* values, int count                                           ) = 0;
        
        //Bool
        virtual void SetBool        (const std::string& name, bool value) = 0;
     
        virtual void SetMat3        (const std::string& name, const glm::mat3& value) = 0;
        virtual void SetMat4        (const std::string& name, const glm::mat4& value) = 0;

        //Int
        virtual void SetDouble      (const std::string& name, double value                              ) = 0;
        virtual void SetDouble2     (const std::string& name, double x, double y                        ) = 0;
        virtual void SetDouble3     (const std::string& name, double x, double y, double z              ) = 0;
        virtual void SetDouble4     (const std::string& name, double x, double y, double z, double w    ) = 0;
      


        //virtual = 0;
        //virtual = 0;
        //virtual = 0;
        //virtual = 0;
        //virtual = 0;
        

		static std::unique_ptr<engine::GameShader> Create(const std::string& vertexSrc, const std::string& fragmentSrc);

        //static std::unique_ptr<engine::GameShader> Create();

	private:

		//std::string LoadShader(backends::RendererAPIType type, const std::string& filepath);
		
        
        //File parsing 
       // const std::string& ParseShader(const std::string& filepath);

		//unsigned int CompileShader(ShaderType type, const std::string& source);
		//unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
		

        /*
        
        
        
        
        */
    };
}


/////////////


//#pragma once
//#include <string>
//#include <memory>
//
//#include <Engine/Res/Assets/Shaders/ShadersLib/shader_library.hpp>
//
//
//namespace engine
//{
//
//  //  enum ShaderType
//  //  {
//
//		//FRAGMENT_SHADER = 0,
//		//VERTEX_SHADER = 1,
//		//GEOMETRY_SHADER = 2 // TODO USELESS for now
//  //     
//  //  };
//
//    class GameShader
//    {
//    public:
//
//        virtual ~GameShader() = default;
//
//		virtual void Bind() = 0;
//		virtual void Unbind() = 0;
//
//        // Optional but VERY useful
//        virtual void SetInt(const std::string& name, int value) = 0;
//        virtual void SetFloat(const std::string& name, float value) = 0;
//
//
//        static std::unique_ptr<engine::GameShader> Create(engine::ShaderTypeID type);
//
//        //static std::unique_ptr<engine::GameShader> Create();
//
//	private:
//
//		std::string LoadShader(backends::RendererAPIType type, const std::string& filepath);
//		
//        
//        //File parsing 
//       // const std::string& ParseShader(const std::string& filepath);
//
//		//unsigned int CompileShader(ShaderType type, const std::string& source);
//		//unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
//		
//
//        /*
//        
//        
//        
//        
//        */
//    };
//}