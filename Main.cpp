#include "Main.h"

using namespace std;

void updateRender(snakeSection & actualSection);
void teleportCheck(sf::Vector2f & snakeHeadPos);
void randomFoodSpawn(snakeFood & mainFood);
bool foodCheck(snakeFood & mainFood, snakeSection & snakeHead);

int main()
{
	//-- Set the resolution to 16:9 preferred resolution for landscape mobile phones --//
	//-- Disable keyrepeat events to make the game tap oriented --//
	//-- Limit the framerate to prevent screen tearing (although this does cause dirty pixels) --//
	sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "Snake - SFML", sf::Style::Close);
	mainWindow.setFramerateLimit(120);
	mainWindow.setKeyRepeatEnabled(false);


	//-- Definitions Section --//
	int score = 0;
	//-- Clock Cycle in miliseconds --//
	int clockCycle = 400;
	string mainDirection = "East";

	vector<snakeSection> snakeBody;

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

	//-- Food's random spawn position --//
	RandGen newGen;

	//-- Definition of the snake's "food" --//
	snakeFood mainFood;
	mainFood.render.setSize(sf::Vector2f(6, 6));
	mainFood.render.setOrigin(3, 3);
	mainFood.render.setPosition(sf::Vector2f(newGen.RandInt(40)*20 + 10, newGen.RandInt(30)*20 + 10));
	mainFood.position = mainFood.render.getPosition();


	//-- Clocks and timers --//
	sf::Clock moveTimer;
	moveTimer.restart();

	//------------------------//

	while (mainWindow.isOpen())
	{
		sf::Event event;
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();

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


		if (moveTimer.getElapsedTime().asMilliseconds() > clockCycle)
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


			//-- Check if the food has been eaten --//
			if (foodCheck(mainFood, snakeHead))
			{
				randomFoodSpawn(mainFood);
				if (clockCycle >= 100)
				{
					clockCycle -= 50;
				}
			}

			moveTimer.restart();
		}

		//-- Get the Mouse position to check button relativity --//
		sf::Vector2i mousePos = sf::Mouse::getPosition(mainWindow);

		//-- Update all the rendered elements --//
		updateRender(snakeHead);

		mainWindow.clear(sf::Color::Black);


		mainWindow.draw(snakeHead.render);
		mainWindow.draw(snakeHead.innerRender);

		mainWindow.draw(mainFood.render);

		mainWindow.display();
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

void randomFoodSpawn(snakeFood & mainFood)
{
	RandGen newGenerator;
	mainFood.render.setPosition(sf::Vector2f(newGenerator.RandInt(40) * 20 + 10, newGenerator.RandInt(30) * 20 + 10));
	mainFood.position = mainFood.render.getPosition();
}

bool foodCheck(snakeFood & mainFood, snakeSection & snakeHead)
{
	if (mainFood.position == snakeHead.position)
	{
		return true;
	}

	return false;
}