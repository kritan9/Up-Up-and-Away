#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"
class animation
{
	sf::Time startTime=sf::seconds(0), aniTime;
	std::string path;
	unsigned int imgNum;
	bool isLoop = 0;
	sf::Texture *texture;
public:
	animation();
	void load(const char [], unsigned int,sf::Time);
	void start(bool);
	sf::Texture frame();
	sf::Texture frame(sf::Time);
	~animation();
};

