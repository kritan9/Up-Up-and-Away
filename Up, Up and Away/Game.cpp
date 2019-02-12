#include"pch.h"
#include "Game.h"
#include "Path.h"
#include <iostream>

Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::window;
sf::Clock Game::clock;
GameObjectManager Game::gameObjectManager;

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
	GameObject background;
	background.Load("Images/background.jpg");
	background.SetScale((float)WIDTH/background.GetImageSize().width,(float) HEIGHT / background.GetImageSize().height);
	Path snakeWay(3000.0f, WIDTH+100.0f,40);
	gameObjectManager.Add("Background", &background);
	gameObjectManager.Add("Path", &snakeWay);
	clock.restart();
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
			
			gameObjectManager.UpdateAll(clock.getElapsedTime().asSeconds());
			clock.restart();
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




