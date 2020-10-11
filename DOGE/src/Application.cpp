#include "pchDOGE.h"
#include "Application.h"

#include "GLFW/glfw3.h"

namespace DOGE
{
	Application* Application::m_Instance = nullptr;

	Application::Application()
	{
		if (!m_Instance)
			m_Instance = this;

		m_Instance->m_Window = std::unique_ptr<WindowsWindow>(WindowsWindow::Create(1280, 720, "Window"));
	}

	Application::~Application()
	{
		delete m_Instance;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(1, 0.2, 0, 1);

			/* Swap front and back buffers */
			glfwSwapBuffers((GLFWwindow*)m_Window->GetWindow());

			/* Poll for and process events */
			glfwPollEvents();
		}
	}
	void Application::OnEvent(Event& e)
	{
		if (e.GetType() == EventType::KeyPressed)
			std::cout << "Merge" << std::endl;
	}
}


