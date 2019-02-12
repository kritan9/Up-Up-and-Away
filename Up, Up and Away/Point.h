#pragma once
#include"pch.h"
#include "Game.h"
class Point
{
public:
	Point();
	Point(float , float , float );
	~Point();
	static float Z;//screen plane
	static float x0, y0, z0;//Stationary Point
	void project();
	float scale;
	sf::Vector2f getPosition();
private:
	float x, y, z;//3d coordinates
	float X, Y;//screen coordinates

	
};

