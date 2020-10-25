#pragma once
#include "pchDOGE.h"

namespace DOGE
{
	enum EventType
	{
		None = 0,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		KeyPressed, KeyReleased, Char,
		WindowClosed, WindowResized,
	};

	class Event
	{
	public:
		bool Handled;

		virtual const char* GetName() const = 0;
		virtual EventType GetType() const = 0;
		virtual std::string ToString() const { return GetName(); }

#define EVENT_SETUP(type)\
		virtual const char* GetName() const override { return #type; }; \
		virtual EventType GetType() const override   { return type; };\
		static EventType GetStaticType() { return type; }

#define ABSTRACT_EVENT_SETUP()\
		virtual const char* GetName() const override = 0; \
		virtual EventType GetType() const override = 0;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetType() == T::GetStaticType())
			{
				m_Event.Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	//std::ostream& operator<<(std::ostream& os, const Event& e)
	//{
	//	os << e.ToString() << std::endl;
	//	return os;
	//}
}
