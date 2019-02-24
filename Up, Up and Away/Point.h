#pragma once
#include"pch.h"
#include "Game.h"
class Point
{
public:
	Point();
	Point(float , float , float );
	void setPoint(float, float, float);
	sf::Vector2f getScreenPoint() { return sf::Vector2f(X,Y); }
	~Point();
	static float Z;//screen plane
	static float x0, y0, z0;//Stationary Point
	void project();
	float Scale();
	float scale;
	sf::Vector2f getPosition();
private:
	float x, y, z;//3d coordinates
	float X, Y;//screen coordinates

	
};

