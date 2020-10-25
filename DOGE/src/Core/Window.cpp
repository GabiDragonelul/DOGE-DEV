#include "pchDOGE.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"
#include "Events/WindowEvent.h"

namespace DOGE
{
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	Window::Window(unsigned int width, unsigned int height, std::string_view title)
		:m_Window(nullptr)
	{
		Init(width, height, title);
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void Window::OnUpdate()
	{
	}

	int Window::Init(unsigned int width, unsigned int height, std::string_view title)
	{
		if (!glfwInit())
			return -1;

		m_Data.Width = width;
		m_Data.Height = height;
		m_Data.Title = title;

		glfwWindowHint(
			GLFW_OPENGL_PROFILE,
			GLFW_OPENGL_CORE_PROFILE
		);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), NULL, NULL);

		if (!m_Window)
		{
			glfwTerminate();
			return -1;
		}

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		glfwSwapInterval(1);

		
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			DOGE_CORE_ASSERT(0, "Failed to initialized GLAD!");
			return -1;
		}

		glViewport(0, 0, 1280, 720);

		glfwSetCursorPosCallback(this->m_Window, [](GLFWwindow* window, double xpos, double ypos) {
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent e(xpos, ypos);

			data.EventCallbackFn(e);
			});

		glfwSetMouseButtonCallback(this->m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent e(button);
					data.EventCallbackFn(e);
				}break;
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent e(button);
					data.EventCallbackFn(e);
				}break;
			}
			});

		glfwSetKeyCallback(this->m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

			WindowData data =  *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent e(key);
					data.EventCallbackFn(e);
				}break;
				case GLFW_RELEASE:
				{
					KeyReleasedEvent e(key);
					data.EventCallbackFn(e);
				}break;
			}
			});

		glfwSetCharCallback(this->m_Window, [](GLFWwindow* window, unsigned int unicode) {
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);

			CharEvent e(unicode);

			data.EventCallbackFn(e);
			
			});

		glfwSetWindowSizeCallback(this->m_Window, [](GLFWwindow* window, int width, int height) {
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowResizedEvent e(width, height);

			data.EventCallbackFn(e);
			});

		glfwSetWindowCloseCallback(this->m_Window, [](GLFWwindow* window) {
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowClosedEvent e;

			data.EventCallbackFn(e);
			});
		return 0;
	}

	void Window::SetEventCallback(const EventCallbackFn& callback)
	{
		m_Data.EventCallbackFn = callback;
	}

	void Window::SetVSync(bool enabled)
	{
		m_Data.VSync = enabled;
	}

	bool Window::IsVSync() const
	{
		return m_Data.VSync;
	}

	void* Window::GetNativeWindow() const
	{
		return m_Window;
	}

	Scope<Window> Window::Create(unsigned int width, unsigned int height, std::string_view title)
	{
#ifdef DOGE_PLATFORM_WINDOWS

		return CreateScope<Window>(width, height, title);
#else
		DOGE_CORE_ASSERT(0, "Unknown platform!");
#endif // DOGE_PLATFORM_WINDOWS

	}
}
