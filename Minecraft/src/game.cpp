#include "game.h"

void Game::run()
{
	renderer.initialize();
	while (renderer.isRunning())
	{
		renderer.render();
	}
}