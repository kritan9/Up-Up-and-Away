
#include"pch.h"
#include "GameObject.h"

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
void GameObject::Update(float dt)
{

}