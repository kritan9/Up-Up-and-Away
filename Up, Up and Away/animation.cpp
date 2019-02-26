#include "animation.h"

animation::animation()
{}
animation::animation(char &p,unsigned int nu,sf::Time t) :aniTime(t),imgNum(nu)
{
	path = &p;
}
void animation::start()
{
	startTime = Game::clockTotal.getElapsedTime();
}
sf::Texture animation::frame()
{
	unsigned int now = static_cast<int>((Game::clockTotal.getElapsedTime() - startTime).asMilliseconds()*imgNum / aniTime.asMilliseconds());
	if (now > (imgNum - 1)) now = (imgNum - 1);
	sf::Texture temp;
	std::string pa = path + '/' + static_cast<char>(now+1)+".jgp";
	temp.loadFromFile(pa);
	return temp;
}
sf::Texture animation::frame(sf::Time ti)
{
	unsigned int now = static_cast<int>(ti.asMilliseconds()*imgNum / aniTime.asMilliseconds());
	if (now > (imgNum - 1)) now = (imgNum - 1);
	sf::Texture temp;
	std::string pa = path + '/' + static_cast<char>(now + 1) + ".jgp";
	temp.loadFromFile(pa);
	return temp;
}
animation::~animation()
{
}
