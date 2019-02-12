#pragma once
#include"pch.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "GameObjectManager.h"
#include "Point.h"

#define WIDTH 1024
#define HEIGHT 768


class GameObjectManager;

class Game
{
private:
	static bool IsExiting();
	static void GameLoop();

	enum GameState {
		Uninitialized,  Paused,
		ShowingMenu, Playing, ShowingScore, Exiting
	};

	static GameState gameState;
	static sf::RenderWindow window;
	static sf::Clock clock;
	
	static GameObjectManager gameObjectManager;

public:
	Game();
	static void Start();
	static sf::RenderWindow& GetWindow() { return window; }
	~Game();
};

