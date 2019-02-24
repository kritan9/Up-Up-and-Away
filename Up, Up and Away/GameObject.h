#pragma once
#include "pch.h"
#include "Game.h"
#define VELOCITY 5000.0f
class GameObject
{
private:
   std::string filename;
   bool isLoaded;
protected:
	sf::Texture texture;
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
	virtual bool isCoin() { return false; }
	virtual bool isObstacle() { return false; }
	virtual bool isPlayer() { return false; }
    void SetPosition(float x,float y);
	virtual sf::Vector2f GetPosition()const;
	bool IsLoaded() const{	return isLoaded;}
	static float velocity;
	virtual bool destroy() { return false; }
	virtual sf::Vector3f size() { return sf::Vector3f(); }
	virtual sf::Vector3f position3d() { return sf::Vector3f(); }
	virtual ~GameObject();
};

