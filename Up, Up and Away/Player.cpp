#include "Player.h"

Player::Player() {}

Player::Player(float Width,float Height)
{
	p.setPoint((WIDTH - Width)*0.5f, 150.0f, 100.0f);
	width = Width; height = Height;
	Load("Images/character.png");
	SetScale(Width*p.scale / texture.getSize().x, p.scale* Height / texture.getSize().y);
	sprite.setTexture(texture);
	SetPosition(p.getScreenPoint().x, p.getScreenPoint().y);

}

void Player::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) sprite.move(sf::Vector2f(-GameObject::velocity*dt, 0.0f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) sprite.move(sf::Vector2f(GameObject::velocity*dt, 0.0f));
	if (sprite.getPosition().x < (WIDTH - GameObject::roadWidth+350.0f)*0.5f) sprite.setPosition((WIDTH - GameObject::roadWidth+350.0f)*0.5f,sprite.getPosition().y);
	if (sprite.getPosition().x > (WIDTH + GameObject::roadWidth - 350.0f)*0.5f - width*p.scale) sprite.setPosition((WIDTH + GameObject::roadWidth - 350.0f)*0.5f-width*p.scale, sprite.getPosition().y);
}

Player::~Player()
{
}
