#pragma once
#include "Game.h"
class Obstacle :
	public GameObject
{
	float x, y, z, roadX; //roadX=distance from road's left side
	Point p;
	float width, height, thickness;
public:

	Obstacle( float w = 300.0f, float h = 100.0f, float th = 50.0f);
	void Update(float dt);
	bool isObstacle() { return true; }
	bool destroy();
	sf::Vector3f position3d();
	sf::Vector3f size();
	~Obstacle();
};

