//
// Created by nazzazel on 23.07.2026.
//


#pragma once
#include "Core/Systems/IEngineSystem.hpp"
#include "Core/Systems/Logger/LoggerSystem.hpp"


namespace engine
{
    class IFile
    {
        public:
        virtual ~IFile() = default;
        virtual size_t Read(void* buffer, size_t size) = 0;
        virtual size_t GetSize() const = 0;
        virtual bool IsOpen() const = 0;

        std::vector<uint8_t> ReadAsBinary()
        {
            size_t size = GetSize();
            std::vector<uint8_t> buffer(size);
            Read(buffer.data(), size);
            return buffer;
        }
    };

    class NativeFile : public IFile//Files with full path ex. C:/../Image.txt.json.png and who is JSON?
    {
    private:
        std::ifstream m_Stream;
        size_t m_Size;

    public:
        NativeFile(const std::string& filepath)
        {
            m_Stream.open(filepath, std::ios::binary | std::ios::ate); // we read the file in binary and place the point at the end
            if (m_Stream.is_open()) {
                m_Size = static_cast<size_t>(m_Stream.tellg()); //Tell where is the pointer aka at the end so we get the size of the file
                m_Stream.seekg(0, std::ios::beg);               //we move the pointer back to the front
            } else {
                m_Size = 0;
            }
        }

        ~NativeFile() override {
            if (m_Stream.is_open())
                m_Stream.close();
        }

        bool IsOpen() const override { return m_Stream.is_open(); } //const due to only being a getter adn not setting anything
        size_t GetSize() const override { return m_Size; }          //const due to only being a getter adn not setting anything

        size_t Read(void* buffer, size_t size) override {
            if (!IsOpen()) return 0;
            m_Stream.read(static_cast<char*>(buffer), size);
            return static_cast<size_t>(m_Stream.gcount());
        }

    };


    class VirtualFile : public IFile // Virtual Files. Files that change their ablosute path based on where the app is placed. Their path is a combination of RootPath supplied by the engine, and relative engine path that is static and relevant in the engine.
    { //TODO important
    private:
        std::ifstream m_Stream;
        size_t m_Size;

    public:
        VirtualFile(const std::string& filepath)
        {
            m_Stream.open(filepath, std::ios::binary | std::ios::ate); // we read the file in binary and place the point at the end
            if (m_Stream.is_open()) {
                m_Size = static_cast<size_t>(m_Stream.tellg()); //Tell where is the pointer aka at the end so we get the size of the file
                m_Stream.seekg(0, std::ios::beg);               //we move the pointer back to the front
            } else {
                m_Size = 0;
            }
        }

        ~VirtualFile() override {
            if (m_Stream.is_open())
                m_Stream.close();
        }

        bool IsOpen() const override { return m_Stream.is_open(); } //const due to only being a getter adn not setting anything
        size_t GetSize() const override { return m_Size; }          //const due to only being a getter adn not setting anything

        size_t Read(void* buffer, size_t size) override {
            if (!IsOpen()) return 0;
            m_Stream.read(static_cast<char*>(buffer), size);
            return static_cast<size_t>(m_Stream.gcount());
        }

    };


    class FileSystem: public IEngineSystem
    {
    public:
        ~FileSystem() override = default;
        Result OnInit() override;// Forced
        Result OnUpdate(float dt) override;
        Result OnShutdown() override;


        void Mount(const std::string& physicalPath);

        std::unique_ptr<IFile> OpenFile(const std::string& virtualPath);

        std::string NormalizePath(const std::string& path);
        std::string GetExecutableDir();

    private:
        std::string m_AssetRoot;

        SystemManager* m_SystemManager = nullptr;
        LoggerSystem* m_Logger = nullptr;

    };
} // engine
