#pragma once

#include "Events/Event.h"

namespace DOGE
{
	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(int width, int height)
			:m_Width(width), m_Height(height) {}

		virtual int GetWidth() const { return m_Width; }
		virtual int GetHeight() const { return m_Height; }
		virtual std::pair<int, int> GetPosition() const { return std::pair<int, int>(m_Width, m_Height); }


		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << this->GetName() << " (" << m_Width << ", " << m_Height << ")";
			return ss.str();
		}

		EVENT_SETUP(EventType::WindowResized)

	private:
		int m_Width, m_Height;
	};

	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent(){}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << this->GetName();
			return ss.str();
		}

		EVENT_SETUP(EventType::WindowClosed)
	};
}
