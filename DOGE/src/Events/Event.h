#pragma once
#include "pchDOGE.h"

namespace DOGE
{
	enum EventType
	{
		None = 0,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		KeyPressed, KeyReleased,
		WindowClosed, WindowResized,
	};

	enum EventCategory
	{
		ApplicationEvent,
		WindowEvent,
		InputEvent,
	};

	class Event
	{
	public:
		virtual const char* GetName() const = 0;
		virtual EventType GetType() const = 0;
		std::string ToString() const { return GetName(); }
	private:
		EventCategory m_Category;
	};

	class EventDispatcher
	{
	private:
		template  <typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& e)
			:e(e){}

		template  <typename T>
		bool Dispatch(const EventFn<T>& fn)
		{
			if (e.GetType() == T::GetStaticType())
				return true;
			return false;
			//TODO continue
		}
	private:
		Event& e;
	};

	std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		os << e.GetName() << std::endl;
	}
}
