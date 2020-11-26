/**
 *  @file   Window.h
 *  @brief  Window base to create window in all plateform
 *  @author Kshitij Azad
 *  @date   November 9, 2020
 ***********************************************/

#pragma once

#include "trpch.h"

#include "Triger/Core/Core.h"
#include "Triger/Events/Event.h"

namespace Triger
{	
	struct WindowProps
	{
		// TODO : To add perameter to show window Icon
		/**
		 * @brief Title of the window
		*/
		std::string Title;
		
		/**
		 * @brief Width of the window
		*/
		unsigned int Width;
		
		/**
		 * @brief Height of the window
		*/
		unsigned int Height;

		/**
		 * @brief Window properties which will pass into GLFWwindow 
		 * @param title 
		 * @param width 
		 * @param height 
		*/
		WindowProps(
			const std::string &title = "Triger Engine",
			unsigned int width = 1280,
			unsigned int height = 720
		)
				: Title(title), Width(width), Height(height)
		{
		}
	};

	/*
	* Interface representing a desktop system based Window
	*/
	class Window
	{
	public:
		/**
		 * @brief 
		*/
		using EventCallbackFn = std::function<void(Event &)>;

		// Will implemented saperately for each plateform

		virtual ~Window() = default;

		/**
		 * @brief will update the window 
		*/
		virtual void OnUpdate() = 0;

		/**
		 * @brief will return the width of window
		 * @return unsigned int window width
		*/
		virtual unsigned int GetWidth() const = 0;

		/**
		 * @brief will return the height of window
		 * @return unsigned int window height 
		*/
		virtual unsigned int GetHeight() const = 0;
		
		/*
		* Window attributes
		*/

		/**
		 * @brief Different event call backs
		 * @param callback 
		*/
		virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
		
		/**
		 * @brief set the VSync property, it will limit your frames to the referesh rate of your display 
		 * @param enabled true/false
		*/
		virtual void SetVSync(bool enabled) = 0;
		
		/**
		 * @brief check if the vSync is enabled or not
		 * @return false/true
		*/
		virtual bool IsVSync() const = 0;

		/**
		 * @brief 
		 * @return 
		*/
		virtual void *GetNativeWindow() const = 0;

		/**
		 * @brief create a window object with given parameter
		 * @param props provided by WindowProps struct
		 * @return Window object
		 * @see Application#OnEvent
		*/
		static Scope<Window> Create(const WindowProps &props = WindowProps());
	};

} // namespace Triger