#include "pchDOGE.h"
#include "Application.h"

namespace DOGE
{
	Application* Application::m_Instance = nullptr;

	Application::Application()
	{
		if (!m_Instance)
			m_Instance = this;
	}

	Application::~Application()
	{
		delete m_Instance;
	}

	void Application::Run()
	{
		while (m_Running)
		{

		}
	}
}


