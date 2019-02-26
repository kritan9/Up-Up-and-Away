#include "animation.h"
#include <iostream>
animation::animation()
{}
void animation::load(const char p[],unsigned int nu,sf::Time t)
{
	aniTime = t;
	imgNum = nu;
	path = p;
	texture = new sf::Texture[imgNum];
	for (int i = 0; i < static_cast<int>(imgNum); i++)
	{
		std::string pa = path + "/" + static_cast<char>(48 + i + 1) + ".jpg";
		texture[i].loadFromFile(pa);
	}
}
void animation::start(bool b)
{
	isLoop = b;
	startTime = Game::clockTotal.getElapsedTime();
}
sf::Texture animation::frame()
{
	unsigned int now = static_cast<int>((Game::clockTotal.getElapsedTime() - startTime).asMilliseconds()*imgNum / aniTime.asMilliseconds());
	if (now > (imgNum - 1)&&isLoop==0) now = (imgNum - 1);
	return texture[now%imgNum];
}
sf::Texture animation::frame(sf::Time ti)
{
	unsigned int now = static_cast<int>(ti.asMilliseconds()*imgNum / aniTime.asMilliseconds());
	if (now > (imgNum - 1) && isLoop==0) now = (imgNum - 1);
	return texture[now%imgNum];
}
animation::~animation()
{
}
