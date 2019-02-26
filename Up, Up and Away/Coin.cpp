#include "Coin.h"

float roadBegin = (WIDTH - GameObject::roadWidth)*0.5f;

Coin::Coin()//x coordinate is from the left side of the road
{
	width = 60.0f; height = 60.0f; thickness = 30.0f;
	roadX = (float)Game::Random(0, (int)(GameObject::roadWidth - thickness));
	z = GameObject::roadLength;
	x =roadBegin +roadX+GameObject::curveX(z); y = Game::Random(1, 3)*Game::yLevel -20.0f;
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
	sprite.setRotation(-20.0f*(x-curveX(z) + width * 0.5f) / GameObject::roadWidth + 10.0f);
	SetPosition(p.getScreenPoint().x, p.getScreenPoint().y);
}

sf::Vector3f Coin::position3d()
{
	return sf::Vector3f(x-10.0f, y, z);
}

sf::Vector3f Coin::size()
{
	return sf::Vector3f(width+20.0f, -height, thickness);
}

bool Coin::destroy() {
	if (z < -10.0f) return true;
	else return false;
}

Coin::~Coin()
{
}
