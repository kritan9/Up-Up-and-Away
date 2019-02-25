#include "animation.h"

animation::animation()
{}
animation::animation(char &p,sf::Time t,unsigned int _n):now(0),time(t),n(_n)
{
	texture = new sf::Texture[n];
	for (int i = 0; i < n; i++)
	{
		std::string temp=path+'/'+static_cast<char> (i)+".jpg";
		texture[i].loadFromFile(temp);
	}
}
sf::Texture animation::frame(sf::Time t)
{
	now = static_cast<int>((t.asMilliseconds()/(n*time.asMilliseconds())));
	if (now > (n-1)) return texture[n-1];
	return texture[now];
}
animation::~animation()
{
}
