#pragma once
#include"pch.h"
#include "Game.h"

class Player :
	public GameObject
{
	Point p;
public:
	Player();
	float width, height;
	Player(float Width, float Height);
	void Update(float dt);
	~Player();
};

