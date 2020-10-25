#include "DOGE.h"

class AppLayer : public DOGE::Layer
{
public:
	void OnUpdate() override
	{

	}

	void OnEvent(DOGE::Event& e) override
	{

	}

	void OnImGuiRender() override
	{

	}
private:
};

class Game : public DOGE::Application
{
public:
	Game()
	{
		//PushLayer(new AppLayer());
	}

	~Game()
	{

	}

private:

};

DOGE::Application* CreateApplication()
{
	return new Game();
}