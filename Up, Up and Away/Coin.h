#pragma once
#include "Game.h"
class Coin :
	public GameObject
{
	float x, y, z,roadX; //roadX=distance from road's left side
	Point p;
	float width, height, thickness;
public:
	Coin();
	void Update(float dt);
	bool destroy();
	bool isCoin() { return true; }
	sf::Vector3f position3d();
	sf::Vector3f size();
	~Coin();
};

