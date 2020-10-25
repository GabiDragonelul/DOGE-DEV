#pragma once
#include "Events\WindowEvent.h"
#include "Window.h"

#include "ImGui/ImGuiLayer.h"

namespace DOGE
{
	class Application
	{
	public:
		Application();
		~Application();
		void Run();
		void OnEvent(Event& e);
		bool OnWindowClosed(WindowClosedEvent& e);
		
		static Application& Get() { return *m_Instance; }
		static void Exit() { m_Instance->m_Running = false; }

		Scope<Window>& GetWindow() { return m_Window; }
	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuyLayer;
		bool m_Running = true;
		static Application* m_Instance;
	};
}


