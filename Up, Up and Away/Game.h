#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
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

public:
	Game();
	static void Start();
	~Game();
};

