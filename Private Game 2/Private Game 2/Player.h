#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <iostream>

class Player
{
	float m_speed;
	bool m_freeRoam{ false }; 
	bool m_resumeMove{ false }; 
	sf::Texture m_texture; 
	sf::Sprite m_body; 
	sf::Vector2f m_position; 

public:

	Player();
	void setupSprite();
	bool move(sf::RectangleShape t_base); 

	sf::Sprite getBody();
	void setBody(sf::Sprite t_body);
};