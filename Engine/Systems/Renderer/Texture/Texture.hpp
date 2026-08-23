#pragma once



namespace engine
{
    class Texture
    {
    public:


        virtual ~Texture() = default;

        virtual void Bind() = 0;
        virtual void UnBind() = 0;

        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;


        virtual int Delete() const = 0;


      //  uint CreateTexture(const char* image, const char* texType, uint id); //File Dir//

    };
}