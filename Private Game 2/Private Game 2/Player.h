#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"

class Player
{
	sf::RectangleShape m_body; 

public:

	Player();
	void setupSprite();
	sf::RectangleShape getBody(); 
};