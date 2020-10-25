#pragma once
#include "Events/Event.h"

struct GLFWwindow;

namespace DOGE
{


	class Window
	{
		using EventCallbackFn = std::function<void(Event&)>;

		struct WindowData
		{
			unsigned int Width, Height;
			std::string Title;
			bool VSync;

			EventCallbackFn EventCallbackFn;
		};

	public:
		Window(unsigned int width = 1280, unsigned int height = 720, std::string_view title = "DOGE");
		~Window();

		virtual void OnUpdate();

		virtual uint32_t GetWidth() const { return m_Data.Width; }
		virtual uint32_t GetHeight() const { return m_Data.Height; }

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback);
		virtual void SetVSync(bool enabled);
		virtual bool IsVSync() const;

		virtual void* GetNativeWindow() const;

		static Scope<Window> Create(unsigned int width = 1280, unsigned int height = 720, std::string_view title = "DOGE");
	private:
		int Init(unsigned int width, unsigned int height, std::string_view title);
	private:
		WindowData m_Data;
		GLFWwindow* m_Window;
	};
}


