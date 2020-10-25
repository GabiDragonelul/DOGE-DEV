#pragma once

#include "Events/Event.h"

namespace DOGE
{
	class Layer
	{
	public:
		Layer(std::string_view name);
		~Layer() {}

		virtual void OnAttach() {}
		virtual void OnDetach() {}

		virtual void OnUpdate() {}
		virtual void OnEvent(Event&) {}
		virtual void OnImGuiRender() {}

		virtual std::string GetName() const { return m_DebugName; }
	private:
		std::string m_DebugName;
	};
}
