#pragma once
#include "pchDOGE.h"

namespace DOGE
{
	struct WindowData
	{
		unsigned int Width, Height;
		std::string Title;
	};

	class Window
	{
	public:
		inline unsigned int GetWidth() const { return m_Data->Width; }
		inline unsigned int GetHeight() const { return m_Data->Height; }
		WindowData* GetData() const { return m_Data; }

		~Window()
		{
			delete m_Data;
		}

		virtual int Init() = 0;
	protected:
		WindowData* m_Data;
	};
}
