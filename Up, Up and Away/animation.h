#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"
class animation
{
	sf::Time startTime, aniTime;
	std::string path;
	unsigned int imgNum;

public:
	animation();
	animation(char &, unsigned int,sf::Time);
	void start();
	sf::Texture frame();
	sf::Texture frame(sf::Time);
	~animation();
};

