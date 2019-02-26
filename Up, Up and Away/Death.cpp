#include "Death.h"
#include <iostream>

Death::Death()
{
	offsetX = 60.0f; offsetY = 10.0f;
	t.loadFromFile("Images/x.png");
	opts[0].loadFromFile("Images/Button.png");
	opts[1].loadFromFile("Images/Button2.png");
	options[0].setTexture(opts[0]);
	options[1].setTexture(opts[0]);
	options[2].setTexture(opts[0]);
	deathBar.setTexture(t);
	deathBar.setPosition(0.5f*(WIDTH - deathBar.getTextureRect().width), 0.5f*(HEIGHT - deathBar.getTextureRect().height));
	for(int i=0;i<3;i++)
	options[i].setPosition(deathBar.getPosition() + sf::Vector2f(offsetX, offsetY + 200.0f + 100.0f*i));
}

void Death::Draw(sf::RenderWindow& window)
{
	window.draw(deathBar);
	for (int i = 0; i < 3; i++)
		window.draw(options[i]);
}
void Death::Update()
{
	static int mouseFlag = 0;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseFlag == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			if (Mouse::Intersect(options[i].getPosition().x, options[i].getPosition().y,(float)options[i].getTextureRect().width,(float)options[i].getTextureRect().height) )
			{
				options[i].setTexture(opts[1]);
				mouseFlag = i + 1;
				break;
			}
			
		}
	}

	if (Game::event.type == sf::Event::MouseButtonReleased && mouseFlag!=0 )
	{
		if (Mouse::Intersect(options[mouseFlag - 1].getPosition().x, options[mouseFlag - 1].getPosition().y, (float)options[mouseFlag - 1].getTextureRect().width, (float)options[mouseFlag - 1].getTextureRect().height))
		{
			if (mouseFlag == 1)
			{
				Game::gameState = Game::Playing;

			}
			else if (mouseFlag == 2) {Game::gameState = Game::Menu;}
			else if (mouseFlag == 3)
			{
				Game::gameState = Game::Exiting;
			}
		}
		options[mouseFlag-1].setTexture(opts[0]);
		mouseFlag = 0;
	}

}

bool Mouse::Intersect(float x,float y,float w,float h)
{
	sf::Vector2i mouse = sf::Mouse::getPosition(Game::window);
	if (mouse.x < x && mouse.x < x + w) return false;
	if (mouse.x > x && mouse.x > x + w) return false;
	if (mouse.y < y && mouse.y < y + h) return false;
	if (mouse.y > y && mouse.y > y + h) return false;
	return true;
}

