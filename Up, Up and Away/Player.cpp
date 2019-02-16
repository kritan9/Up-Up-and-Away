#include "Player.h"
#define PLAYERVELOCITY 3000.0f
#include <iostream>

float TimePeriod = 1.0f;
float uSpeed = 480.0f / TimePeriod;
float acc = 2 * uSpeed / TimePeriod;  
float t;
Player::Player() {}

Player::Player(float Width,float Height)
{
	x = (WIDTH - Width)*0.5f; y = 200.0f; z = 50.0f;
	p.setPoint(x,y,z);
	jump = 0;
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && jump == 0) { jump = 1; clock.restart(); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && jump == 0) { jump = -1;  clock.restart(); }

	if (x < (WIDTH - GameObject::roadWidth)*0.5f) x= (WIDTH - GameObject::roadWidth)*0.5f;
	if (x > (WIDTH + GameObject::roadWidth)*0.5f - width*p.scale) x=(WIDTH + GameObject::roadWidth )*0.5f-width*p.scale;

	if (jump == 1) 
	{
		t = clock.getElapsedTime().asSeconds();
		y = 200.0f + uSpeed*t-0.5f*acc*t*t;
		if (y < 200.0f) { y = 200.0f; jump = 0; }
	}
	if (jump == -1)
	{
		t = clock.getElapsedTime().asSeconds();
		y = 200.0f - uSpeed * t + 0.5f*acc*t*t;
		if (y > 200.0f) { y = 200.0f; jump = 0;  }
	}

	p.setPoint(x, y, z);
	sprite.setRotation(-40.0f*(x+width*0.5) / GameObject::roadWidth + 20.0f);
	SetPosition(p.getScreenPoint().x, p.getScreenPoint().y);
}

sf::Vector3f Player::position3d()
{
	return sf::Vector3f(x, y, z);
}

Player::~Player()
{
}
