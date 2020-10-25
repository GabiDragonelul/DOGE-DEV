#pragma once
#include "pchDOGE.h"

namespace DOGE
{
	class Input
	{
	public:
		static bool IsKeyPressed(int keycode);

		static bool IsMouseButtonPressed(int mouseButton);
		static std::pair<double, double> GetMousePosition();
		static double GetMouseX();
		static double GetMouseY();
	};
}
