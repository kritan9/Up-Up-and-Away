#pragma once
#include"pch.h"
#include "Game.h"


class Path :
	public GameObject
{
private:
	float Length, Width;
	int noOfSpikes;
	Point p1, p2, p3, p4; //four corners of the road
	sf::Color color;
	std::vector<sf::ConvexShape> road;
	std::vector<sf::ConvexShape> spike;
	sf::Color color2;
	float offset;
public:
	Path();
	Path(float l, float w,int n);
	void Draw(sf::RenderWindow&);
	void Update(float dt);
	void Road(float);
	~Path();
};

