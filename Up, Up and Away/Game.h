#pragma once
#include"pch.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Point.h"
#include "Death.h"
#include "Menu.h"
#include "CharacterMenu.h"
#include <SFML/Audio.hpp>
#include <time.h>

#define WIDTH 1024
#define HEIGHT 768

class GameObjectManager;
class GameObject;
class Death;
class Menu;
class CharacterMenu;

class Game
{
private:
	static void GameLoop();
	static sf::Clock clock;
	static GameObjectManager gameObjectManager;
	static Death d;
	static Menu m;
	static CharacterMenu cm;
public:
	Game();
	enum GameState {
		Uninitialized,  Paused,
		Menu, Playing, Leaderboard, Exiting, Dead,Character
	};
	static float spawnTime;
	static bool IsExiting();
	static int Random(int a,int b);
	static int level;
	static float yLevel;
	static GameState gameState;
	static sf::RenderWindow window;
	static sf::Clock clockTotal;
	static sf::Event event;
	static sf::Sound coin;
	static sf::Sound death;
	static void Start();
	static sf::RenderWindow& GetWindow() { return window; }
	~Game();
};

