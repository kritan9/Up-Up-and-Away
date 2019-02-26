#pragma once
#include "Game.h"
class Menu
{
	sf::Texture t;
	sf::Sprite menuBar;
	sf::Texture opts[2];
	sf::Sprite options[4];
	float offsetX, offsetY;
public:
	Menu();
	void Draw(sf::RenderWindow&);
	void Update();
	~Menu();
};

