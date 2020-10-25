#pragma once

#include  "Event.h"
#include "Core/MouseCodes.h"

namespace DOGE
{

	class MouseButtonEvent : public Event
	{
	public:
		virtual MouseCode GetButton() const { return m_Button; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << this->GetName() << "-> " << m_Button;
			return ss.str();
		}

	protected:
		MouseButtonEvent(MouseCode button)
			:m_Button(button){}

		MouseCode m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(MouseCode button)
			:MouseButtonEvent(button)
		{}

		EVENT_SETUP(EventType::MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(MouseCode button)
			:MouseButtonEvent(button)
		{}

		EVENT_SETUP(EventType::MouseButtonReleased)
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(double x, double y)
			:m_X(x), m_Y(y)
		{}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << this->GetName() << " (" << m_X << ", " << m_Y << ")";
			return ss.str();
		}

		EVENT_SETUP(EventType::MouseMoved)
	protected:
		double m_X, m_Y;
	};

	//class MouseScrolledEvent : public Event
	//{
	//public:
	//	MouseScrolledEvent(int nr, double x, double y)
	//		:MouseEvent(x, y), m_Nr(nr)
	//	{}
	//
	//	virtual int GetNr() const { return m_Nr; }
	//
	//	virtual std::string ToString() const override
	//	{
	//		std::stringstream ss;
	//		ss << this->GetName() << " (" << m_X << ", " << m_Y << ") number of scrolls: " << m_Nr;
	//		return ss.str();
	//	}
	//
	//	EVENT_SETUP(EventType::MouseMoved)
	//private:
	//	int	m_Nr;
	//};
}
