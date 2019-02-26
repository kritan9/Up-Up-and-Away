#include "CharacterMenu.h"
#include "iostream"

int CharacterMenu::pos = 0;
CharacterMenu::CharacterMenu()
{
	offsetX = 60.0f; offsetY = 100.0f;
	t.loadFromFile("Images/x.png");
	dem[0].loadFromFile("Images/demo.png");
	demo[0].setTexture(dem[0]);
	dem[1].loadFromFile("Images/demo2.png");
	demo[1].setTexture(dem[1]);
	menuBar.setTexture(t);
	menuBar.setPosition(0.5f*(WIDTH - menuBar.getTextureRect().width), 0.5f*(HEIGHT - menuBar.getTextureRect().height));
	tx.loadFromFile("Images/text2.png");
	txt.setTexture(tx);
	txt.setPosition(menuBar.getPosition());
	opts[0].loadFromFile("Images/Button.png");
	opts[1].loadFromFile("Images/Button2.png");
	arr[0].loadFromFile("Images/left.png");
	arr[1].loadFromFile("Images/right.png");
	arrows[0].setTexture(arr[0]);
	arrows[1].setTexture(arr[1]);
	arrows[0].setPosition(menuBar.getPosition()+sf::Vector2f(10.0f, menuBar.getTextureRect().height*0.5f-50.0f));
	arrows[1].setPosition(menuBar.getPosition() + sf::Vector2f(menuBar.getTextureRect().width-60.0f, menuBar.getTextureRect().height*0.5f - 50.0f));
	options.setTexture(opts[0]);
	options.setPosition(menuBar.getPosition() + sf::Vector2f(offsetX, offsetY + 100.0f*3));
	demo[0].setPosition(menuBar.getPosition() + sf::Vector2f(10.0f, offsetY-85.0f ));
	demo[1].setPosition(menuBar.getPosition() + sf::Vector2f(100.0f, offsetY - 50.0f));
}

void CharacterMenu::Draw(sf::RenderWindow& window)
{
	window.draw(menuBar);
	window.draw(options);
	window.draw(arrows[0]);
	window.draw(arrows[1]);
	window.draw(demo[pos % 2]);
	window.draw(txt);
}

void CharacterMenu::Update()
{
	static int mouseFlag = 0;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseFlag == 0)
	{
			if (Mouse::Intersect(options.getPosition().x, options.getPosition().y, (float)options.getTextureRect().width, (float)options.getTextureRect().height))
			{
				options.setTexture(opts[1]);
				mouseFlag = 1;
			}
			for (int i = 0; i < 2; i++)
			{
				if (Mouse::Intersect(arrows[i].getPosition().x, arrows[i].getPosition().y, (float)arrows[i].getTextureRect().width, (float)arrows[i].getTextureRect().height))
				{
					mouseFlag = 2 + i;
					break;
				}

			}
	}

	if (Game::event.type == sf::Event::MouseButtonReleased && mouseFlag != 0)
	{
		if (mouseFlag == 1)
		{
			if (Mouse::Intersect(options.getPosition().x, options.getPosition().y, (float)options.getTextureRect().width, (float)options.getTextureRect().height))
			{
				Game::gameState = Game::Menu;
			}
			options.setTexture(opts[0]);
		}
		else
		{
			if (Mouse::Intersect(arrows[mouseFlag-2].getPosition().x, arrows[mouseFlag-2].getPosition().y, (float)arrows[mouseFlag-2].getTextureRect().width, (float)arrows[mouseFlag-2].getTextureRect().height))
			{
				if (mouseFlag == 2) pos--;
				else pos++;
			}

		}
		mouseFlag = 0;
	}

}

CharacterMenu::~CharacterMenu()
{
}
