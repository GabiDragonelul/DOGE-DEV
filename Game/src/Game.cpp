#include "DOGE.h"

class Game : public DOGE::Application
{
public:
	Game()
	{

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