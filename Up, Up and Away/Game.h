#pragma once
#include"pch.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Point.h"
#include <time.h>

#define WIDTH 1024
#define HEIGHT 768

class GameObjectManager;
class GameObject;

class Game
{
private:
	static void GameLoop();
	static sf::Clock clock;
	static GameObjectManager gameObjectManager;
	static float spawnTime;
public:
	Game();
	enum GameState {
		Uninitialized,  Paused,
		Menu, Playing, ShowingScore, Exiting, Dead
	};
	static bool IsExiting();
	static int Random(int a,int b);
	static int level;
	static float yLevel;
	static GameState gameState;
	static sf::RenderWindow window;
	static sf::Clock clockTotal;
	static sf::Event event;
	static void Start();
	static sf::RenderWindow& GetWindow() { return window; }
	~Game();
};

