#pragma once
#include "Window.h"

struct GLFWwindow;

namespace DOGE
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(unsigned int width, unsigned int height, std::string_view title);
		~WindowsWindow();

		virtual int Init() override;

		static WindowsWindow* Create(unsigned int width, unsigned int height, std::string_view title);
		void* GetWindow() const { return m_Window; }
	private:
		GLFWwindow* m_Window;
	};
}


