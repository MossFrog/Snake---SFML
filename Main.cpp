#include "Main.h"


using namespace std;

void updateRender(snakeSection & actualSection);
void teleportCheck(sf::Vector2f & snakeHeadPos);

int main()
{
	//-- Set the resolution to 16:9 preferred resolution for landscape mobile phones --//
	//-- Disable keyrepeat events to make the game tap oriented --//
	//-- Limit the framerate to prevent screen tearing (although this does cause dirty pixels) --//
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake - SFML", sf::Style::Close);
	window.setFramerateLimit(120);
	window.setKeyRepeatEnabled(false);


	//-- Definitions Section --//
	string mainDirection = "East";

	//-- rectangleShapes used as a default renders for each snakeSection --//
	sf::RectangleShape defaultRect;
	defaultRect.setSize(sf::Vector2f(20, 20));
	defaultRect.setOrigin(10, 10);

	sf::RectangleShape defaultInnerRect;
	defaultInnerRect.setSize(sf::Vector2f(18, 18));
	defaultInnerRect.setOrigin(9, 9);
	defaultInnerRect.setFillColor(sf::Color::Black);

	//-- Definition of the snake "head" --//
	snakeSection snakeHead;
	snakeHead.position = sf::Vector2f(410, 310);
	snakeHead.render = defaultRect;
	snakeHead.innerRender = defaultInnerRect;

	//-- Clocks and timers --//
	sf::Clock moveTimer;
	moveTimer.restart();

	//------------------------//

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{

			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			mainDirection = "North";
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			mainDirection = "South";
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			mainDirection = "West";
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			mainDirection = "East";
		}


		if (moveTimer.getElapsedTime().asMilliseconds() > 400)
		{
			if (mainDirection == "East")
			{
				snakeHead.position.x += 20;
			}

			else if (mainDirection == "West")
			{
				snakeHead.position.x -= 20;
			}

			else if (mainDirection == "South")
			{
				snakeHead.position.y += 20;
			}

			else if (mainDirection == "North")
			{
				snakeHead.position.y -= 20;
			}

			//-- Handle Teleportation --//
			teleportCheck(snakeHead.position);

			moveTimer.restart();
		}

		//-- Get the Mouse position to check button relativity --//
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		//-- Update all the rendered elements --//
		updateRender(snakeHead);

		window.clear(sf::Color::Black);


		window.draw(snakeHead.render);
		window.draw(snakeHead.innerRender);

		window.display();
	}

	return 0;
}

void updateRender(snakeSection & actualSection)
{
	actualSection.render.setPosition(actualSection.position);
	actualSection.innerRender.setPosition(actualSection.position);
}

void teleportCheck(sf::Vector2f & snakeHeadPos)
{
	if (snakeHeadPos.x > 800)
	{
		snakeHeadPos.x = 10;
	}

	else if (snakeHeadPos.x < 0)
	{
		snakeHeadPos.x = 790;
	}

	else if (snakeHeadPos.y < 0)
	{
		snakeHeadPos.y = 590;
	}

	else if (snakeHeadPos.y > 600)
	{
		snakeHeadPos.y = 10;
	}
}