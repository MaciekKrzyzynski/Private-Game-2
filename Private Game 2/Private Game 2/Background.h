#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"

class Background 
{
	sf::RectangleShape m_basePlatform; 
	sf::Vector2f m_basePlatformSize{ 3000.0f, 200.0f };

public:

	Background();
	void setupSprite(); 
	sf::RectangleShape getBasePlatform();
};