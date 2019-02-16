#include"pch.h"
#include "Main.h"

int main()
{
	Game::window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "Up Up And Away");
	while(Game::gameState!=Game::Exiting)
	Game::Start();
	return 0;
}