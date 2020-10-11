#pragma once
#include "Events\Event.h"
#include "Platform/Windows/WindowsWindow.h"

namespace DOGE
{
	class Application
	{
	public:
		Application();
		~Application();
		void Run();
		void OnEvent(Event& e);

		static Application* Get() { return m_Instance; }
	private:
		std::unique_ptr<WindowsWindow> m_Window;
		bool m_Running = true;
		static Application* m_Instance;
	};
}


