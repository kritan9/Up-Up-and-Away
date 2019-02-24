#include "Coin.h"
float roadBegin = (WIDTH - GameObject::roadWidth)*0.5f;
Coin::Coin() {}

Coin::Coin(float X, float Y)//x coordinate is from the left side of the road
{
	width = 60.0f; height = 60.0f; thickness = 30.0f;
	roadX = X;
	z = GameObject::roadLength;
	x =roadBegin +X+GameObject::curveX(z); y = Y-20.0f;
	p.setPoint(x, y, z);
	Load("Images/coin.png");
	SetScale(width*p.Scale() / texture.getSize().x, p.Scale()* height / texture.getSize().y);
	SetPosition(p.getScreenPoint().x, p.getScreenPoint().y);
}

void Coin::Update(float dt)
{
	z -= velocity * dt;
	x = roadX+roadBegin + GameObject::curveX(z);
	p.setPoint(x, y, z);
	SetScale(width*p.Scale() / texture.getSize().x, p.Scale()* height / texture.getSize().y);
	sprite.setRotation(-40.0f*(x-curveX(z) + width * 0.5f) / GameObject::roadWidth + 20.0f);
	SetPosition(p.getScreenPoint().x, p.getScreenPoint().y);
}

sf::Vector3f Coin::position3d()
{
	return sf::Vector3f(x, y, z);
}

sf::Vector3f Coin::size()
{
	return sf::Vector3f(width, -height, thickness);
}

bool Coin::destroy() {
	if (z < 0.0f) return true;
	else return false;
}

Coin::~Coin()
{
}
