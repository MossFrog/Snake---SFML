#include "Main.h"


using namespace std;

int main()
{
	//-- Set the resolution to 16:9 preferred resolution for landscape mobile phones --//
	//-- Disable keyrepeat events to make the game tap oriented --//
	//-- Limit the framerate to prevent screen tearing (although this does cause dirty pixels) --//
	sf::RenderWindow window(sf::VideoMode(720, 450), "Snake - SFML", sf::Style::Close);
	window.setFramerateLimit(120);
	window.setKeyRepeatEnabled(true);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//-- If the specified key is pressed push the player upwards --//
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


		window.clear(sf::Color::Black);


		//window.draw(playerShape);

		window.display();
	}



	return 0;
}