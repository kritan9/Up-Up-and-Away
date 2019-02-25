#include <cmath>
#include "GameObject.h"
#include <iostream>
#define PI 3.14159265f
float sineConstant =  PI /(2* GameObject::roadLength*0.9f);
float GameObject::velocity = VELOCITY;
float GameObject::roadLength = 5000.0f, GameObject::roadWidth = WIDTH-100.0f ;
float GameObject::curveX(float z) 
{
	if (Game::clockTotal.getElapsedTime().asSeconds()<1.0f) return 0;
	else {
		if (z > roadLength*0.1) {
			float temp;
			float dt = Game::clockTotal.getElapsedTime().asSeconds() - 1.0f;
			static sf::Clock timePause;
			static float amp = 0;
			static int flag = 0,flag2=0;
			if (flag%2 == 0)
			{
				if ( flag2 == 0)
				{
					amp = 50.0f*dt;
					if (amp > 600.0f) { flag2 = 1; timePause.restart(); }
				}
				else if (timePause.getElapsedTime().asSeconds()<8.0f);
				else amp = 1200.0f - 50.0f * (dt-8.0f);
			}
			else
			{
				if (flag2 == 0)
				{
					amp = -50.0f * dt;
					if (amp < -600.0f) { flag2 = 1; timePause.restart(); }
				}
				else if (timePause.getElapsedTime().asSeconds() < 8.0f);
				else  amp = 50.0f * (dt-8.0f) - 1200.0f;
			}
			if ((flag % 2 == 0 && amp < 0.0f) || (flag % 2 == 1 && amp > 0.0f)) { Game::clockTotal.restart(); flag++; amp = 0.0f; flag2 = 0; }
			temp = amp*(sinf(sineConstant*(roadLength*0.9f-z))-sinf(sineConstant*(roadLength*0.8f)));
			return temp;
		}
		else return 0;
	};
};

GameObject::GameObject()
{
	isLoaded = false;
}


GameObject::~GameObject()
{
}

void GameObject::Load(std::string file)
{
	if (texture.loadFromFile(file) == false)
	{
		filename = "";
		isLoaded = false;
	}
	
	else
	{
		filename = file;  
		sprite.setTexture(texture);
		isLoaded = true;
	}
}

void GameObject::SetScale( float x,float y)
{
	sprite.setScale(sf::Vector2f(x,y));
}

void GameObject::CropImage(int x, int y, int width, int height)
{
	sprite.setTextureRect(sf::IntRect(x,y,width,height));
}

sf::IntRect GameObject::GetImageSize()
{
	return sprite.getTextureRect();
}

void GameObject::Draw(sf::RenderWindow & renderWindow)
{
	if (isLoaded)
	{
		renderWindow.draw(sprite);
	}
}

void GameObject::SetPosition(float x, float y)
{
	if (isLoaded)
	{
		sprite.setPosition(x, y);
	}
}
sf::Vector2f GameObject::GetPosition() const
{
	return sprite.getPosition();
}
void GameObject::Update(float dt)
{

}