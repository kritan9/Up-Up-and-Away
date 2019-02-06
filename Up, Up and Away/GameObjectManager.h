#pragma once
#include "pch.h"
#include"GameObject.h"
class GameObject;
class GameObjectManager
{
public:
		GameObjectManager();
		~GameObjectManager();
		void Add(std::string name, GameObject* gameObject);
		void Remove(std::string name);
		int GetObjectCount() const;
		GameObject* Get(std::string name) const;
	
		 void DrawAll(sf::RenderWindow& renderWindow);
private:
	std::map<std::string, GameObject*> gameObjects;
		
		struct GameObjectDeallocator
		{
		  void operator()(const std::pair<std::string, GameObject*> & p) const
		{
			delete p.second;
		}
	};

};

