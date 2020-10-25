#include "pchDOGE.h"
#include "Application.h"

extern DOGE::Application* CreateApplication();

int main(int argc, char** argv)
{
	DOGE::Log::Init();

	auto app = CreateApplication();

	delete app;

	return 0;
}