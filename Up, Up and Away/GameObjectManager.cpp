#include"pch.h"
#include "GameObjectManager.h"
#include <iostream>

int BoxCollision(sf::Vector3f aPos, sf::Vector3f aSize, sf::Vector3f bPos, sf::Vector3f bSize)
{
	if (aPos.x < bPos.x && aPos.x < (bPos.x + bSize.x) && (aPos.x + aSize.x) < bPos.x && (aPos.x + aSize.x) < (bPos.x + bSize.x)) return 0;
	if (aPos.x > bPos.x && aPos.x > (bPos.x + bSize.x) && (aPos.x + aSize.x) > bPos.x && (aPos.x + aSize.x) > (bPos.x + bSize.x)) return 0;
	if (aPos.y < bPos.y && aPos.y < (bPos.y + bSize.y) && (aPos.y + aSize.y) < bPos.y && (aPos.y + aSize.y) < (bPos.y + bSize.y)) return 0;
	if (aPos.y > bPos.y && aPos.y > (bPos.y + bSize.y) && (aPos.y + aSize.y) > bPos.y && (aPos.y + aSize.y) > (bPos.y + bSize.y)) return 0;
	if (aPos.z < bPos.z && aPos.z < (bPos.z + bSize.z) && (aPos.z + aSize.z) < bPos.z && (aPos.z + aSize.z) < (bPos.z + bSize.z)) return 0;
	if (aPos.z > bPos.z && aPos.z > (bPos.z + bSize.z) && (aPos.z + aSize.z) > bPos.z && (aPos.z + aSize.z) > (bPos.z + bSize.z)) return 0;
	return 1;
}

GameObjectManager::GameObjectManager()
{
}


GameObjectManager::~GameObjectManager()
{
   std::for_each(gameObjects.begin(), gameObjects.end(), GameObjectDeallocator());
   obstacles.clear();
}

void GameObjectManager::Add(std::string name, GameObject* gameObject)
{
	if (gameObject->isCoin() || gameObject->isObstacle())	obstacles.push_back(gameObject);
    else gameObjects.insert(std::pair<std::string, GameObject*>(name, gameObject));
}

void GameObjectManager::Remove(std::string name)
{
   std::map<std::string, GameObject*>::iterator results = gameObjects.find(name);
   if (results != gameObjects.end())	 
   {	    delete results->second;	  
			 gameObjects.erase(results);  
   }
}

GameObject* GameObjectManager::Get(std::string name) const
{
   std::map<std::string, GameObject*>::const_iterator results = gameObjects.find(name);
   if (results == gameObjects.end())	    
	   return NULL;
   return results->second;
}

int GameObjectManager::GetObjectCount() const
{
   return gameObjects.size();
}


void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{		
	std::map<std::string, GameObject*>::const_iterator itr = gameObjects.begin();
	int length = obstacles.size();
		 while (itr != gameObjects.end())
		{
			 if(!itr->second->isPlayer())
		     itr->second->Draw(renderWindow);
		     itr++;
		}

		 for (int i = 0; i < length; i++)
		 {
			 obstacles[i]->Draw(renderWindow);
		 }
		 gameObjects.find("Player")->second->Draw(renderWindow);
}

void GameObjectManager::UpdateAll(float timeDelta)
{
	std::map<std::string, GameObject*>::const_iterator itr = gameObjects.begin();
	int length = obstacles.size();

	while (itr != gameObjects.end())
	{
		itr->second->Update(timeDelta);
		itr++;
	}
	for (int i = 0; i < length; i++)
	{
		if (obstacles[i]->destroy())
		{
			obstacles.erase(obstacles.begin() + i);
			length -= 1; i--;
		}
	}
	length = obstacles.size();
	for(int i=0;i<length;i++)
		obstacles[i]->Update(timeDelta);

}
void GameObjectManager::Collision(Player &player)
{
	int length = obstacles.size();
	int i = 0;
	while (i<length)
	{
		if (BoxCollision(player.position3d(), player.size(), obstacles[i]->position3d(), obstacles[i]->size()) == 1)
		{
			if (obstacles[i]->isCoin())
			{
				Game::coin.play();
				obstacles.erase(obstacles.begin()+i);
				length -= 1; i--;
			}
			else
			{
				Game::death.play();
				Game::gameState = Game::Dead;
			}
			
		}
		i++;
	}

}

void GameObjectManager::Reset()
{
	obstacles.clear();
	Game::level = 1;
	GameObject::velocity = VELOCITY;
	Game::spawnTime = 300.0f / GameObject::velocity;
}
