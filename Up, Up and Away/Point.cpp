
#include"pch.h"
#include "Point.h"
Point::Point(){}
Point::Point(float x,float y,float z)
{
	this->x = x; this->y = y; this -> z = z;
}


Point::~Point()
{
}

float Point::Z = 0;
float Point::x0 =WIDTH/2, Point::y0 = HEIGHT, Point::z0 = -200;

void Point::project()
{
	float temp = (z0 - Z) / (z0 - z);
	X = x0 + temp * (x - x0);
	Y = HEIGHT -y0 - temp * (y - y0);
}

sf::Vector2f Point::getPosition()
{
	return sf::Vector2f(X, Y);
}