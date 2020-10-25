#include "pchDOGE.h"
#include "Application.h"

#include "GLFW/glfw3.h"

#include "Events/KeyEvent.h"

#include "Core/Input.h"

namespace DOGE
{
	Application* Application::m_Instance = nullptr;

	Application::Application()
	{
		if (!m_Instance)
			m_Instance = this;

		m_Instance->m_Window = Window::Create();
		m_Instance->m_Window->SetEventCallback(DOGE_BIND_EVENT_FN(Application::OnEvent));
	
		m_ImGuyLayer = new ImGuiLayer();
		m_Instance->Run();
	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		while (m_Running)
		{

			m_ImGuyLayer->Begin();



			m_ImGuyLayer->End();

			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(1, 0.2, 0, 1);

			/* Swap front and back buffers */
			glfwSwapBuffers((GLFWwindow*)m_Window->GetNativeWindow());

			/* Poll for and process events */
			glfwPollEvents();
		}
	}

	void Application::OnEvent(Event& e)
	{
		DOGE_CORE_INFO(e.ToString());

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(DOGE_BIND_EVENT_FN(Application::OnWindowClosed));
	}

	bool Application::OnWindowClosed(WindowClosedEvent& e)
	{
		Application::Exit();
		return true;
	}
}


