#include "Player.h"
#define PLAYERVELOCITY 3000.0f
Player::Player() {}

Player::Player(float Width,float Height)
{
	x = (WIDTH - Width)*0.5f; y = 150.0f; z = 100.0f;
	p.setPoint(x,y,z);
	width = Width; height = Height;
	Load("Images/character.png");
	SetScale(Width*p.scale / texture.getSize().x, p.scale* Height / texture.getSize().y);
	sprite.setTexture(texture);
	SetPosition(p.getScreenPoint().x, p.getScreenPoint().y);

}

void Player::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))	x-=PLAYERVELOCITY*dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))   x+=PLAYERVELOCITY*dt;
	if (x < (WIDTH - GameObject::roadWidth)*0.5f) x= (WIDTH - GameObject::roadWidth)*0.5f;
	if (x > (WIDTH + GameObject::roadWidth)*0.5f - width*p.scale) x=(WIDTH + GameObject::roadWidth )*0.5f-width*p.scale;

	p.setPoint(x, y, z);
	sprite.setRotation(-40.0f*(x+width*0.5) / GameObject::roadWidth + 20.0f);
	SetPosition(p.getScreenPoint().x, p.getScreenPoint().y);
}

Player::~Player()
{
}
