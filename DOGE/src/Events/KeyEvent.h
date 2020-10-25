#pragma once

#include "Event.h"
#include "Core/KeyCodes.h"

namespace DOGE
{
	class KeyEvent : public Event
	{
	public:
		virtual KeyCode GetKey() const { return m_Key; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << this->GetName() << "-> " << m_Key;
			return ss.str();
		}
	protected:
		KeyEvent(KeyCode key)
			:m_Key(key)
		{}

		KeyCode m_Key;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode key)
			:KeyEvent(key){}

		EVENT_SETUP(EventType::KeyPressed)
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(KeyCode key)
			:KeyEvent(key) {}

		EVENT_SETUP(EventType::KeyReleased)
	};

	class CharEvent : public Event
	{
	public:
		CharEvent(unsigned int unicode)
			:m_Char(unicode){}

		virtual char GetChar() const { return m_Char; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << this->GetName() << "-> " << m_Char;
			return ss.str();
		}

		EVENT_SETUP(EventType::Char)
	private:
		char m_Char;
	};
}
