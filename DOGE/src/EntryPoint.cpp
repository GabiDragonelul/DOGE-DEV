#include "pchDOGE.h"
#include "Application.h"

extern DOGE::Application* CreateApplication();

int main(int argc, char** argv)
{
	auto app = CreateApplication();

	app->Get()->Run();

	delete app;

	return 0;
}