#include"pch.h"
#include "Game.h"
#include <iostream>

void DrawQuad(Point *p, sf::RenderWindow& window,sf::Color color)
{
	sf::ConvexShape shape(4);
	shape.setPoint(0, p[0].getPosition());
	shape.setPoint(1, p[1].getPosition());
	shape.setPoint(2, p[2].getPosition());
	shape.setPoint(3, p[3].getPosition());
	shape.setFillColor(color);
	window.draw(shape);
}

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
	window.setFramerateLimit(60);
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
			window.clear(sf::Color::Blue);
			
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


