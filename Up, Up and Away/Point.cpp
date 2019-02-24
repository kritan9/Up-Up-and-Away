
#include"pch.h"
#include "Point.h"
Point::Point(){}
Point::Point(float x,float y,float z)
{
	this->x = x; this->y = y; this -> z = z;
	this->project();
}
void Point::setPoint(float x, float y, float z)
{
	this->x = x; this->y = y; this->z = z;
	this->project();
}


Point::~Point()
{
}

float Point::Z = 0;
float Point::x0 =WIDTH/2, Point::y0 = 300.0f, Point::z0 = -500;

void Point::project()
{
	scale = (z0 - Z) / (z0 - z);
	X = x0 + scale * (x - x0);
	Y = HEIGHT -y0 - scale * (y - y0);
}

sf::Vector2f Point::getPosition()
{
	return sf::Vector2f(X, Y);
}

float Point::Scale() 
{
	if (scale > 1.0f) return 1.0f;
	else return scale;
};