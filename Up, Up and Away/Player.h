#pragma once
#include"pch.h"
#include "Game.h"

class Player :
	public GameObject
{
	float x, y, z;
	Point p;
public:
	Player();
	float width, height;
	Player(float Width, float Height);
	void Update(float dt);
	sf::Vector3f position3d();
	~Player();
};

