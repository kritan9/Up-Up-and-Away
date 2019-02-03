#include "Game.h"

Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::window;
sf::Clock Game::clock;


Game::Game()
{
}

Game::~Game()
{
}

void Game::Start()
{
	if (gameState != Uninitialized)
		return;
	window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "Up Up And Away");
	gameState = Game::Playing;

	while (!IsExiting())
	{
		GameLoop();
	}

	window.close();
}

bool Game::IsExiting()
{
	if (gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	sf::Event event;
	window.pollEvent(event);

		switch (gameState)
		{
		case Game::Playing:
		{
			
			window.clear();
			
			gameObjectManager.DrawAll(window);
			
			window.display();

			if (event.type == sf::Event::Closed)
			{
				gameState = Game::Exiting;
			}
			break;
		}
		}

}

GameObjectManager Game::gameObjectManager;


