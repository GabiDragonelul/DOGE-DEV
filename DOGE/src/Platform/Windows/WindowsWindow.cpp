#include "pchDOGE.h"
#include "WindowsWindow.h"

#include "GLFW/glfw3.h"

namespace DOGE
{
	WindowsWindow::WindowsWindow(unsigned int width, unsigned int height, std::string_view title)
		:m_Window(nullptr)
	{
		m_Data = new WindowData{ width, height, title.data() };
		Init();
	}

	WindowsWindow::~WindowsWindow()
	{
		delete m_Window;
	}

	int WindowsWindow::Init()
	{
		if (!glfwInit())
			return -1;

		m_Window = glfwCreateWindow(m_Data->Width, m_Data->Height, m_Data->Title.c_str(), NULL, NULL);

		if (!m_Window)
		{
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(m_Window);

		glfwSetKeyCallback(this->m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

			});

		return 0;
	}

	WindowsWindow* WindowsWindow::Create(unsigned int width, unsigned int height, std::string_view title)
	{
		return new WindowsWindow(width, height, title);
	}
}
