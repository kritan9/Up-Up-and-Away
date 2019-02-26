#pragma once
#include"pch.h"
#include "Game.h"

class Player :
	public GameObject
{
	float x, y, z;
	int jump;
	int yLevel;
	Point p;
	sf::Clock clock;
	float width, height;
public:
	Player();
	Player(float Width, float Height);
	bool isPlayer() { return true; }
	void Update(float dt);
	void Reset();
	void Reset(int);
	sf::Vector3f position3d();
	sf::Vector3f size();
	~Player();
};

