#include "Menu.h"



Menu::Menu()
{
	offsetX = 60.0f; offsetY = 70.0f;
	t.loadFromFile("Images/x.png");
	opts[0].loadFromFile("Images/Button.png");
	opts[1].loadFromFile("Images/Button2.png");
	options[0].setTexture(opts[0]);
	options[1].setTexture(opts[0]);
	options[2].setTexture(opts[0]);
	options[3].setTexture(opts[0]);
	menuBar.setTexture(t);
	menuBar.setPosition(0.5f*(WIDTH - menuBar.getTextureRect().width), 0.5f*(HEIGHT - menuBar.getTextureRect().height));
	for (int i = 0; i < 4; i++)
		options[i].setPosition(menuBar.getPosition() + sf::Vector2f(offsetX, offsetY + 100.0f*i));
}

void Menu::Draw(sf::RenderWindow& window)
{
	window.draw(menuBar);
	for (int i = 0; i < 4; i++)
		window.draw(options[i]);
}

void Menu::Update()
{
	static int mouseFlag = 0;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseFlag == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (Mouse::Intersect(options[i].getPosition().x, options[i].getPosition().y, (float)options[i].getTextureRect().width, (float)options[i].getTextureRect().height))
			{
				options[i].setTexture(opts[1]);
				mouseFlag = i + 1;
				break;
			}

		}
	}

	if (Game::event.type == sf::Event::MouseButtonReleased && mouseFlag != 0)
	{
		if (Mouse::Intersect(options[mouseFlag - 1].getPosition().x, options[mouseFlag - 1].getPosition().y, (float)options[mouseFlag - 1].getTextureRect().width, (float)options[mouseFlag - 1].getTextureRect().height))
		{
			if (mouseFlag == 1)
			{
				Game::gameState = Game::Playing;
			}
			//else if (mouseFlag == 2) {Game::gameState = Game::LeaderBoard;}
			//else if (mouseFlag == 3) {Game::gameState = Game::Credits;}
			else if (mouseFlag == 4)
			{
				Game::gameState = Game::Exiting;
			}
		}
		options[mouseFlag - 1].setTexture(opts[0]);
		mouseFlag = 0;
	}

}

Menu::~Menu()
{
}
