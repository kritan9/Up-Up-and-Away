#include "Obstacle.h"

float roadBeg = (WIDTH - GameObject::roadWidth)*0.5f;
Obstacle::Obstacle() {}

Obstacle::Obstacle(float X, float Y, float w,float h,float th)//x coordinate is from the left side of the road
{
	width = w; height = h; thickness = th;
	roadX = X;
	z = GameObject::roadLength;
	x = roadBeg + X + GameObject::curveX(z); y = Y;
	p.setPoint(x, y, z);
	Load("Images/Obstacle.png");
	SetScale(width*p.Scale() / texture.getSize().x, p.Scale()* height / texture.getSize().y);
	SetPosition(p.getScreenPoint().x, p.getScreenPoint().y);
}

void Obstacle::Update(float dt)
{
	z -= velocity * dt;
	x = roadX + roadBeg + GameObject::curveX(z);
	p.setPoint(x, y, z);
	SetScale(width*p.Scale() / texture.getSize().x, p.Scale()* height / texture.getSize().y);
	sprite.setRotation(-20.0f*(x-curveX(z) + width * 0.5f) / GameObject::roadWidth + 10.0f);
	SetPosition(p.getScreenPoint().x, p.getScreenPoint().y);
}

sf::Vector3f Obstacle::position3d()
{
	return sf::Vector3f(x, y, z);
}

sf::Vector3f Obstacle::size()
{
	return sf::Vector3f(width, -height, thickness);
}

bool Obstacle::destroy() {
	if (z < 0.0f) return true;
	else return false;
}

Obstacle::~Obstacle()
{
}