#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <iostream>

class Background 
{
	int m_direction = 0; 
	float m_speed;
	sf::RectangleShape m_basePlatform; 
	sf::RectangleShape m_boundWallL;
	sf::RectangleShape m_boundWallR;
	sf::Vector2f m_basePlatformSize{ 3000.0f, 200.0f };
	sf::Vector2f m_basePlatformPos{ -10.0f, 610.0f };

public:

	Background();
	void setupSprite(); 
	void move(bool t_resume); 
	sf::RectangleShape getBasePlatform();
	sf::RectangleShape getBoundWallL(); 
	sf::RectangleShape getBoundWallR();
};