/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : Event.h
//   Created On  : 07/11/2020
//   Updated On  : 29/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once
#include <functional>

#include "Triger/Debug/Instrumentor.h"

#include "Triger/Core/Base.h"

namespace Triger
{
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
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,
		AppTick,
		AppUpdate,
		AppRender,

		// This Events are Covered in KeyEvent.h file
		KeyPressed,
		KeyReleased,
		KeyTyped,

		// This Events are Covered in MouseEvent.h file
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	/*
	* BIT -> BIT(x) (1 << x)  * BIT(2) => 100
	* This Enum is to apply multipal event to the same category
	* eg. Keyboaed Event is a Application event as well as Input event
	
	*/

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type)                                                  \
	static EventType GetStaticType() { return EventType::type; }                \
	virtual EventType GetEventType() const override { return GetStaticType(); } \
	virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
	virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char *GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event &event)
			: m_Event(event)
		{
		}

		// F will be deduced by the compiler
		template <typename T, typename F>
		bool Dispatch(const F &func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled != func(static_cast<T &>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event &m_Event;
	};

	inline std::ostream &operator<<(std::ostream &os, const Event &e)
	{
		return os << e.ToString();
	}

} // namespace Triger
