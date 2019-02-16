#pragma once
#include "pch.h"
#include "Game.h"
class GameObject
{
private:
   sf::Texture texture;
   std::string filename;
   bool isLoaded;
protected:
	sf::Sprite  sprite;
public:
	GameObject();
	static float curveX(float z);
	static float roadLength, roadWidth;
	virtual void Load(std::string file);
	virtual void SetScale( float x,float y);
    void CropImage(int x, int y, int width, int height);
	sf::IntRect GetImageSize();
	virtual void Draw(sf::RenderWindow&);
	virtual void Update(float dt);
    void SetPosition(float x,float y);
	virtual sf::Vector2f GetPosition()const;
	bool IsLoaded() const{	return isLoaded;}
	static float velocity;
	virtual ~GameObject();
};

