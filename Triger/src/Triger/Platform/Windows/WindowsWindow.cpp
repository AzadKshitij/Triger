#include "trpch.h"
#include "WindowsWindow.h"
#include "Triger/Events/ApplicationEvent.h"
#include "Triger/Events/KeyEvent.h"
#include "Triger/Events/MouseEvent.h"

#include "Triger/Platform/OpenGL/OpenGLContext.h"
#include <stb_image.h>

// #include "Triger.h"

namespace Triger
{

	/************************************************************************|
	*                                                                        |
	* s_GLFWInitialized __                                                   |
	*                     |__ Create(const WindowProps& props)               |
	*                         |__ WindowsWindow(const WindowProps& props)    |
	*                             |__ Init(const WindowProps& props)         |
	*                                                                        |
	*************************************************************************/

	static uint8_t s_GLFWWindowCount = 0;

	/*
	* TO get any kind of error from GLFW
	*/
	static void GLFWErrorCallback(int error, const char* description)
	{
		TR_CORE_ERROR("GLFW Error ({0}) : {1}",error, description);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}


	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		// TR_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (s_GLFWWindowCount == 0)
		{
			TR_CORE_INFO("Initializing GLFW");
			int success = glfwInit();
			TR_CORE_ASSERT(success, "Could not intialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);

		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		++s_GLFWWindowCount;
		
		int width, height, chennal;
		stbi_uc* img = stbi_load("assets/Logos/Icon.png", &width, &height, &chennal, 0); //rgba channels 
		if (img == NULL) std::cout << "Icon Can Not Be Loaded\n in WindowsWindow.cpp line: 72";
		m_Images->height = height;
		m_Images->width = width;
		m_Images[0].pixels = img;
		glfwSetWindowIcon(m_Window, 1, m_Images);

		m_Context = CreateScope<OpenGLContext>(m_Window);
		m_Context->Init();
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;
				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});
		/*
		*@param[in] window The window that received the event.
		* @param[in] key The[keyboard key](@ref keys) that was pressed or released.
		* @param[in] scancode The system - specific scancode of the key.
		* @param[in] action `GLFW_PRESS`, `GLFW_RELEASE` or `GLFW_REPEAT`.  Future
		*/

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				/*
				* TODO: Need to convert GLFW Keycodes to Triger keycode to be platform indepandent
				*/
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						data.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, 1);
						data.EventCallback(event);
						break;
					}
					default:
						break;
				}
			});
		/*
		 *  @param[in] button The [mouse button](@ref buttons) that was pressed or
		 *  released.
		 *  @param[in] action One of `GLFW_PRESS` or `GLFW_RELEASE`.  Future releases
		 *  may add more actions.
		 *  @param[in] mods Bit field describing which [modifier keys](@ref mods) were
		 *  held down.
		*/
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						data.EventCallback(event);
						break;
					}
					default:
						break;
				}
			});
		/*
		*  @param[in] xoffset The scroll offset along the x-axis.
		*  @param[in] yoffset The scroll offset along the y-axis.
		*/
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);

			});
		/*
		*  @param[in] xpos The new cursor x-coordinate, relative to the left edge of
		*  the content area.
		*  @param[in] ypos The new cursor y-coordinate, relative to the top edge of the
		*  content area.
		*/
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
		/*
		*  @param[in] window The window whose callback to set.
		*  @param[in] callback The new callback, or `NULL` to remove the currently set
		*  callback.
		*  @return The previously set callback, or `NULL` if no callback was set or the
		*  library had not been [initialized](@ref intro_init).
		*/

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				KeyTypedEvent event(keycode);
				data.EventCallback(event);
			});




	}

	void WindowsWindow::Shutdown()
	{
		// To destroy Window when it closed
		glfwDestroyWindow(m_Window);

		if (--s_GLFWWindowCount == 0)
		{
			TR_CORE_INFO("Terminating GLFW");
			glfwTerminate();
		}
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

} // namespace Triger