#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class animation
{
	unsigned int now;
	std::string path;
	sf::Texture *texture;
	sf::Time time;
	unsigned int n;
public:
	animation();
	animation(char &, sf::Time,unsigned int);
	sf::Texture frame(sf::Time);
	~animation();
};

