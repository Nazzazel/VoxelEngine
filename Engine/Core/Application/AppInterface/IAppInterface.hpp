//
// Created by nazzazel on 21.07.2026.
//


#pragma once

namespace engine
{
    class IAppInterface {
    public:
        virtual ~IAppInterface() = default;
        virtual class TimeSystem& GetTimeSystem() = 0;
        virtual class LoggerSystem& GetLoggerSystem() = 0;

        virtual class PlatformSystem&   GetPlatformSystem   () = 0;
        virtual class WindowSystem&     GetWindowSystem     () = 0;

        virtual class EventSystem&      GetEventSystem      () = 0;
        virtual class RendererSystem&   GetRendererSystem   () = 0;
        virtual class FileSystem&       GetFileSystem       () = 0;
        virtual class AssetSystem&      GetAssetSystem      () = 0;
        //() = 0;

        virtual class InputSystem& GetInputSystem() = 0;


/*
        *         virtual class PlatformSystem&   GetPlatformSystem   () = 0;
                virtual class WindowSystem&     GetWindowSystem     () = 0;

                virtual class EventSystem&      GetEventSystem      () = 0;
                virtual class RendererSystem&   GetRendererSystem   () = 0;
                virtual class FileSystem&       GetFileSystem       () = 0;
                virtual class AssetSystem&      GetAssetSystem      () = 0;
 *
 *
 */

        //virtual class IFileSystem* GetFileSystem() = 0;

    };

}
