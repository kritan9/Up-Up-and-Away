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
sf::Sound Game::coin;
sf::Sound Game::death;
sf::Music Game::bkgMusic;
sf::SoundBuffer coinBuffer;
sf::SoundBuffer deathBuffer;
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
	window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "Up Up And Away",sf::Style::Default);
	coinBuffer.loadFromFile("Sounds/coin.wav");
	coin.setBuffer(coinBuffer);
	deathBuffer.loadFromFile("Sounds/death.wav");
	death.setBuffer(deathBuffer);
	bkgMusic.openFromFile("Sounds/Stereo Madness.wav");
	bkgMusic.setVolume(60);
	bkgMusic.setLoop(true);
	bkgMusic.play();
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

			static int q = 1; static float delT = 0.0f; static float delT2 = 0.0f;
			delT += clock.getElapsedTime().asSeconds(); delT2 += clock.getElapsedTime().asSeconds();
			if (delT2 > 3.0f)
			{
				delT2 = 0.0f;
				level++;
				if (GameObject::velocity <= 20000.0f)
				GameObject::velocity += 500.0f;
				spawnTime = 500.0f / GameObject::velocity;
			}
			if (delT >= spawnTime)
			{
				if (q == 4)
				{	
					if(Random(0,level)!=0) gameObjectManager.Add(" ", new Obstacle());
					q = 0;
				}
				else
				{
					if (Random(0, 1) == 1) gameObjectManager.Add(" ",new Coin());
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
			bkgMusic.stop();
			bkgMusic.play();
		}
		}

}