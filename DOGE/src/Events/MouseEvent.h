#pragma once

#include  "Event.h"

namespace DOGE
{
	class MouseEvent : public Event
	{
	public:
		MouseEvent(int x, int y)
			:m_X(x), m_Y(y){}

	private:
		int m_X;
		int m_Y;
	};
}
