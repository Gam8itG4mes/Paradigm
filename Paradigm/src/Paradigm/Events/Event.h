#pragma once

#include "Paradigm/Core.h"

#include <string>
#include <functional>

namespace Paradigm
{
	//Events are currently blocking
	//this means when an even occurs
	//it is immediately dealt with 
	//might be better to buffer the events
	//and deal with them in a more systematic way
	//during the event stage of an update()

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender, 
		KeyPressed, KeyReleased, 
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EvenCategoryInput        = BIT(1),
		EventCategoryKeyBoard    = BIT(2), 
		EventCategoryMouse       = BIT(3), 
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){return EventType::##type;}\
								virtual EventType GetEventType() const override {return GetStaticType(); }\
								virtual const char* GetName() const override {return #type;}
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


	class PARADIGM_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool (T&)>;
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
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private: 
		Event& m_Event;
	};

	inline std::ostream& operator << (std::ostream os, const Event& e)
	{
		return os << e.ToString();
	}

}

