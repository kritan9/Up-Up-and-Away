#include"pch.h"
#include "Game.h"
#include "GameObjectManager.h"
#include "Path.h"
#include "Player.h"
#include "Coin.h"
#include "Obstacle.h"
#include "string.h"
#include <iostream>

Game::GameState Game::gameState = Game::Menu;
sf::RenderWindow Game::window;
sf::Clock Game::clock;
sf::Clock Game::clockTotal;
GameObjectManager Game::gameObjectManager;
Player player(150.0f, 150.0f);
sf::Event Game::event;
int Game::level = 1;
float Game::yLevel = 150.0f;
float Game::spawnTime = 300.0f / GameObject::velocity;
sf::Sound Game::coin;
sf::Sound Game::death;
sf::SoundBuffer coinBuffer;
sf::SoundBuffer deathBuffer;
Death Game::d;
Menu Game::m;
CharacterMenu Game::cm;
std::string audioFiles[]={ "Sounds/menuLoop.ogg","Sounds/StereoMadness.ogg","Sounds/TimeMachine.ogg","Sounds/TheoryOfEverything.ogg","Sounds/Jumper.ogg","Sounds/HexagonForce.ogg","Sounds/GeometricalDominator.ogg","Sounds/Electroman.ogg","Sounds/Electrodynamix.ogg","Sounds/DryOut.ogg","Sounds/Deadlocked.ogg","Sounds/Cycles.ogg","Sounds/Clutterfunk.ogg","Sounds/Clubstep.ogg","Sounds/CantLetGo.ogg","Sounds/BlastProcessing.ogg","Sounds/BaseAfterBase.ogg","Sounds/BackOnTrack.ogg" };
int audioNum = 18; int audioPos = 0;
sf::Music bkgMusic[18];


Game::Game()
{
}

Game::~Game()
{
}

int Game::Random(int a, int b)
{
	if (a == b) return a;
	return rand() % (b - a + 1) + a;
}
void Game::Start()
{
	window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "Up Up And Away");
	coinBuffer.loadFromFile("Sounds/coin.wav");
	coin.setBuffer(coinBuffer);
	coin.setVolume(30);
	deathBuffer.loadFromFile("Sounds/death.wav");
	death.setBuffer(deathBuffer);
	for (int i = 0; i < audioNum; i++)
	{
		bkgMusic[i].openFromFile(audioFiles[i]);
		bkgMusic[i].setVolume(50);
	}
	audioPos = 0;
	bkgMusic[audioPos].play();
	GameObject background;
	player.Reset();
	background.Load("Images/background.jpg");
	background.SetScale((float)WIDTH / background.GetImageSize().width, (float)HEIGHT / background.GetImageSize().height);
	Path snakeWay(GameObject::roadLength, GameObject::roadWidth+200.0f,55);
	gameObjectManager.Add("Background", &background);
	gameObjectManager.Add("Path", &snakeWay);
	gameObjectManager.Add("Player",&player );
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
				spawnTime = 300.0f / GameObject::velocity;
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
					if (Random(0, 1) == 0) gameObjectManager.Add(" ",new Coin());
					q++;
				}
				delT = 0.0f;
			}

			if (bkgMusic[audioPos].getStatus() == sf::Music::Stopped)
			{
				audioPos = Random(1, audioNum - 1);
				bkgMusic[audioPos].play();
			}

			window.clear();
			gameObjectManager.UpdateAll(clock.getElapsedTime().asSeconds());
			clock.restart();
			gameObjectManager.DrawAll(window);
			window.display();

			gameObjectManager.Collision(player);
			if(gameState==Dead)
			{
				gameObjectManager.Reset();
				player.Reset();
				bkgMusic[audioPos].stop();
				audioPos = 0;
				bkgMusic[audioPos].play();
			}
			if (event.type == sf::Event::Closed)
			{
				gameState = Game::Exiting;
			}
			break;
		}
		
		case Dead:
		{
			window.clear();
			d.Update();
			d.Draw(window);
			window.display();

			if (gameState == Playing)
			{
				clock.restart();
				clockTotal.restart();
				bkgMusic[audioPos].stop();
			}
			if (event.type == sf::Event::Closed)
			{
				gameState = Game::Exiting;
			}

			break;
		}
		case Menu:
		{
			window.clear();
			m.Update();
			m.Draw(window);
			window.display();

			if (gameState == Playing)
			{
				bkgMusic[audioPos].stop();
				audioPos = Random(1, audioNum - 1);
				bkgMusic[audioPos].play();
				player.Reset(CharacterMenu::pos);
				clock.restart();
				clockTotal.restart();
			}
			if (event.type == sf::Event::Closed)
			{
				gameState = Game::Exiting;
			}
			break;
		}
		case Character:
		{
			window.clear();
			cm.Update();
			cm.Draw(window);
			window.display();

			if (event.type == sf::Event::Closed)
			{
				gameState = Game::Exiting;
			}
			break;
		}

		}

}




