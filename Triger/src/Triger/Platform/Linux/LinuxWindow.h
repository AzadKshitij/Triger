/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : LinuxWindow.h
//   Created On  : 05/03/2021
//   Updated On  : 05/03/2021
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/

#pragma one

#include "Triger/Core/Window.h"
#include "Triger/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Triger
{
    class LinuxWindow : public Window
    {
    public:
        LinuxWindow(const WindowProps &props);
        virtual ~LinuxWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        // Window attributes
        inline void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

        inline virtual void *GetNativeWindow() const { return m_Window; }

    private:
        virtual void Init(const WindowProps &props);
        virtual void Shutdown();

    private:
        GLFWwindow *m_Window;

        GLFWimage m_Images[1];

        Scope<GraphicsContext> m_Context;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}