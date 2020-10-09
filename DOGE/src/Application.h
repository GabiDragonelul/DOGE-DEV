#pragma once
#include <Events\Event.h>

namespace DOGE
{
	class Application
	{
	public:
		Application();
		~Application();
		void Run();

		static Application* Get() { return m_Instance; }
	private:
		bool m_Running = true;
		static Application* m_Instance;
	};
}


