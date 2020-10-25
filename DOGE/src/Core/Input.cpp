#include "pchDOGE.h"
#include "Input.h"
#include "Application.h"

#include "GLFW/glfw3.h"

namespace DOGE
{
	bool Input::IsKeyPressed(int keycode)
	{
		int state = glfwGetKey((GLFWwindow*)Application::Get().GetWindow()->GetNativeWindow(), keycode);
		if (state == GLFW_PRESS)
			return true;
		return false;
	}

	bool Input::IsMouseButtonPressed(int mouseButton)
	{
		int state = glfwGetMouseButton((GLFWwindow*)Application::Get().GetWindow()->GetNativeWindow(), mouseButton);
		
		if (state == GLFW_PRESS)
			return true;
		return false;
	}

	std::pair<double, double> Input::GetMousePosition()
	{
		double x, y;
		glfwGetCursorPos((GLFWwindow*)Application::Get().GetWindow()->GetNativeWindow(), &x, &y);

		return std::pair<double, double>(x, y);
	}

	double Input::GetMouseX()
	{
		auto [x, y] = GetMousePosition();
		return x;
	}

	double Input::GetMouseY()
	{
		auto [x, y] = GetMousePosition();
		return y;
	}
}
