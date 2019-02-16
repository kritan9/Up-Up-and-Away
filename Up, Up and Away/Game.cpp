#include"pch.h"
#include "Game.h"
#include "Path.h"
#include "Player.h"
#include <iostream>

Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::window;
sf::Clock Game::clock;
sf::Clock Game::clockTotal;
GameObjectManager Game::gameObjectManager;
sf::Event Game::event;

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
	gameState = Game::Playing;
	GameObject background;
	background.Load("Images/background.jpg");
	background.SetScale((float)WIDTH / background.GetImageSize().width, (float)HEIGHT / background.GetImageSize().height);

	Player player(150.0f,150.0f);
	Path snakeWay(GameObject::roadLength, GameObject::roadWidth,55);
	gameObjectManager.Add("Background", &background);
	gameObjectManager.Add("Path", &snakeWay);
	gameObjectManager.Add("Player",&player );
	clock.restart();
	clockTotal.restart();
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




