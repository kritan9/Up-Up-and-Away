#pragma once
#include "Game.h"

namespace Mouse
{
	bool Intersect(float,float,float, float);
}

class Death
{
	sf::Texture t;
	sf::Sprite deathBar;
	sf::Texture opts[2];
	sf::Sprite options[3];
	float offsetX, offsetY;
public:
	Death();
	void Draw(sf::RenderWindow&);
	void Update();
};

