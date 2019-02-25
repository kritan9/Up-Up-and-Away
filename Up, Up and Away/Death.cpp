#include "Death.h"


bool Mouse::Intersect(sf::Vector2f &pos, sf::Vector2f &size)
{
	sf::Vector2i mouse = sf::Mouse::getPosition();
	sf::Vector2i p = sf::Vector2i(int(pos.x),int(pos.y));
	sf::Vector2i s = sf::Vector2i(int(size.x), int(size.y));
	if (mouse.x < p.x && mouse.x < p.x + size.x) return false;
	if (mouse.x > p.x && mouse.x > p.x + size.x) return false;
	if (mouse.y < p.y && mouse.y < p.y + size.y) return false;
	if (mouse.y > p.y && mouse.y > p.y + size.y) return false;
	return true;
}