#pragma once
#include "pchDOGE.h"

namespace DOGE
{
	enum EventTypes
	{
		MousePressedEvent, MouseReleasedEvent, MouseRepeatedEvent,
		KeyPressedEvent, KeyReleasedEvent, KeyRepeatedEvent, 
		MouseMovedEvent, 
	};

	class Event
	{
	public:
		virtual std::string GetName() const = 0;
		virtual EventTypes GetType() const = 0;


	};

	class EventHandler
	{
	protected:
		using EventHandlerFunction = std::function<bool(Event&)>;
	private:
		void Dispatch(const Event& e)
		{

		}
	};
}
