#include"pch.h"
#include "Game.h"
#include "GameObjectManager.h"
#include "Path.h"
#include "Player.h"
#include "Coin.h"
#include "Obstacle.h"
#include <iostream>

Game::GameState Game::gameState = Game::Playing;//this should be initialized to menu
sf::RenderWindow Game::window;
sf::Clock Game::clock;
sf::Clock Game::clockTotal;
GameObjectManager Game::gameObjectManager;
Player player(150.0f, 150.0f);
sf::Event Game::event;
int Game::level = 1;
float Game::yLevel = 150.0f;
float Game::spawnTime = 500.0f / GameObject::velocity;

Game::Game()
{
}

Game::~Game()
{
}

int Game::Random(int a, int b)
{
	return rand() % (b - a + 1) + a;
}
void Game::Start()
{
	window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "Up Up And Away");
	GameObject background;
	player.Reset();
	background.Load("Images/background.jpg");
	background.SetScale((float)WIDTH / background.GetImageSize().width, (float)HEIGHT / background.GetImageSize().height);
	Path snakeWay(GameObject::roadLength, GameObject::roadWidth,55);
	gameObjectManager.Add("Background", &background);
	gameObjectManager.Add("Path", &snakeWay);
	gameObjectManager.Add("Player",&player );
	clock.restart();
	clockTotal.restart();
	while (!IsExiting() )
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
		case Playing:
		{

			static int q = 1; static float delT = 0.0f;
			delT += clock.getElapsedTime().asSeconds();
			if (delT >= spawnTime)
			{
				if (q == 4)
				{	
					if(Random(0,level)!=0) gameObjectManager.Add(" ", new Obstacle((int)Random(0, (int)(GameObject::roadWidth - 400.0f)), Random(1, 3)*yLevel));
					q = 0;
				}
				else
				{
					if (Random(0, 1) == 1) gameObjectManager.Add(" ",new Coin((int)Random(0,(int)(GameObject::roadWidth-400.0f)), Random(1, 3)*yLevel));
					q++;
				}
				delT = 0.0f;
			}

			window.clear();
			gameObjectManager.UpdateAll(clock.getElapsedTime().asSeconds());
			clock.restart();
			gameObjectManager.DrawAll(window);
			window.display();

			gameObjectManager.Collision(player);

			if (event.type == sf::Event::Closed)
			{
				gameState = Game::Exiting;
			}
			break;
		}
		case Dead:
		{
			gameObjectManager.Reset();
			player.Reset();
			gameState = Playing;
		}
		}

}




