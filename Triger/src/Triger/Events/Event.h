#pragma once

#include "trpch.h"
#include "Triger/Core.h"

namespace Triger {
	// Will be change in future
	/*
	* Events in Triger are currently blocking, meaning when an event occurs it
	* immediately gets dispatched and must be dealt with right then an there.
	* For the future, a better strategy might be to buffer events in an event
	* bus and process them during the "event" part of the update stage.
	*/


	
	//This Enum class describes the event types
	
	enum class EventType
	{
		None = 0,

		// This Events are Covered in ApplicationEvent.h file
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,

		// This Events are Covered in KeyEvent.h file
		KeyPressed, KeyReleased, KeyTyped,
		
		// This Events are Covered in MouseEvent.h file
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	/*
	* BIT -> BIT(x) (1 << x)  * BIT(2) => 100
	* This Enum is to apply multipal event to the same category
	* eg. Keyboaed Event is a Application event as well as Input event
	
	*/

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication   =   BIT(0),
		EventCategoryInput         =   BIT(1),
		EventCategoryKeyboard      =   BIT(2),
		EventCategoryMouse         =   BIT(3),
		EventCategoryMouseButton   =   BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }



	class TRIGER_API Event
	{
	public:
		/*
		* To check is the event is been handled or not
		* Can be used to dispatch events to different Layers
		*/
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		// To get the name of the event
		virtual const char* GetName() const = 0;
		//
		virtual int GetCategoryFlags() const = 0;
		// Returns the name of the event
		virtual std::string ToString() const { return GetName(); }

		/*
		* To filterout different event to their respective category
		*/
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	
	};

	// To dispatch Events on basis of their type
	class EventDispatcher
	{
		// T -> Any Event type
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}