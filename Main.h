#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "randgen.h"

//-- Struct for storing sections of the Snake (Blocks) --//
struct snakeSection
{
	sf::Vector2f position;
	sf::RectangleShape render;
	sf::RectangleShape innerRender;
};

