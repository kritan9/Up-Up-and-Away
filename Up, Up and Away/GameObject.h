#pragma once
#include "pch.h"
#include "Game.h"
class GameObject
{
private:
   sf::Sprite  sprite;
   sf::Texture texture;
   std::string filename;
   bool isLoaded;
public:
	GameObject();

	virtual void Load(std::string file);
	virtual void SetScale( float x,float y);
    void CropImage(int x, int y, int width, int height);
	sf::IntRect GetImageSize();
	virtual void Draw(sf::RenderWindow&);
	virtual void Update(float dt);
    void SetPosition(float x,float y);
	virtual ~GameObject();
};

