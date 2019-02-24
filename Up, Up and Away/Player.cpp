#include "Player.h"
#define PLAYERVELOCITY 3000.0f
#include <iostream>

float TimePeriod = 0.5f;
float uSpeed = 4.05f*Game::yLevel / TimePeriod;
float acc = 2 * uSpeed / TimePeriod;  
float t;
Player::Player() {}

void Player::Reset() { x = (WIDTH - width)*0.5f; y = 250.0f; z = 50.0f; jump = 0; yLevel = 2; }

Player::Player(float Width,float Height)
{
	x = (WIDTH - Width)*0.5f; y = 250.0f; z = 50.0f;
	p.setPoint(x,y,z);
	jump = 0;  yLevel = 2;
	width = Width; height = Height;
	Load("Images/character2.png");
	SetScale(Width*p.scale / texture.getSize().x, p.scale* Height / texture.getSize().y);
	SetPosition(p.getScreenPoint().x, p.getScreenPoint().y);

}

void Player::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))	x-=PLAYERVELOCITY*dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))   x+=PLAYERVELOCITY*dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && jump == 0 && (yLevel==2 || yLevel==1))
	{ 
		jump = 1; clock.restart(); 
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && jump == 0 && (yLevel == 2 || yLevel == 3))
	{ 
		jump = -1;  clock.restart();
	}

	if (x < (WIDTH - GameObject::roadWidth)*0.5f) x= (WIDTH - GameObject::roadWidth)*0.5f;
	if (x > (WIDTH + GameObject::roadWidth)*0.5f - width*p.scale) x=(WIDTH + GameObject::roadWidth )*0.5f-width*p.scale;

	if (jump == 1) 
	{
		t = clock.getElapsedTime().asSeconds();
		y = (yLevel*Game::yLevel-50.0f) + uSpeed*t-0.5f*acc*t*t;
		if (yLevel == 2) { if (y >= ((yLevel+1)*Game::yLevel - 50.0f)) { yLevel = 3; y=yLevel*Game::yLevel - 50.0f;  jump = 0; } }
		if (yLevel == 1) { if (y >= ((yLevel + 1)*Game::yLevel - 50.0f)) { yLevel = 2; y=yLevel*Game::yLevel - 50.0f;  jump = 0; } }
	}
	if (jump == -1)
	{
		t = clock.getElapsedTime().asSeconds();
		y = (yLevel*Game::yLevel - 50.0f) - uSpeed * t + 0.5f*acc*t*t;
		if (yLevel == 2) { if (y <= ((yLevel - 1)*Game::yLevel - 50.0f)) { yLevel = 1; y=yLevel*Game::yLevel - 50.0f;  jump = 0;} }
		if (yLevel == 3) { if (y <= ((yLevel - 1)*Game::yLevel - 50.0f)) { yLevel = 2; y=yLevel*Game::yLevel - 50.0f;  jump = 0;} }
	}

	p.setPoint(x, y, z);
	sprite.setRotation(-40.0f*(x+width*0.5f) / GameObject::roadWidth + 20.0f);
	SetPosition(p.getScreenPoint().x, p.getScreenPoint().y);
}

sf::Vector3f Player::position3d()
{
	return sf::Vector3f(x, y, z);
}

sf::Vector3f Player::size()
{
	return sf::Vector3f(width, -50.0f, -300.0f);
}

Player::~Player()
{
}
