#include "Main.h"


using namespace std;

//-- Struct for storing sections of the Snake (Blocks) --//
struct snakeSection
{
	sf::Vector2f position;
	sf::RectangleShape render;
	sf::RectangleShape innerRender;
};

void updateRender(snakeSection & actualSection);

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
	snakeHead.position = sf::Vector2f(100, 100);
	snakeHead.render = defaultRect;
	snakeHead.innerRender = defaultInnerRect;

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
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			
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