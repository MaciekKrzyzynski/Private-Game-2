#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <iostream>

class Background 
{
	int m_direction = 0; 
	float m_speed;
	bool m_launch{ false }; 
	bool m_grappleFall{ false }; 
	bool m_grapplePlayerTransition{ false }; 
	float m_lineLenght;
	float m_lineLenghtCheck;
	sf::RectangleShape m_basePlatform; 
	sf::RectangleShape m_boundWallL;
	sf::RectangleShape m_boundWallR;
	sf::CircleShape m_grapple; 
	sf::Vector2f m_basePlatformSize{ 3000.0f, 200.0f };
	sf::Vector2f m_basePlatformPos{ -10.0f, 610.0f };
	sf::Vector2f m_distance;
	sf::Vector2f m_distanceCheck;

	sf::Vector2f m_gravity{ 0.0f, 0.0f };
	float m_jumpHeight = 12.0f;
	float m_grappleGravity = 0.0f;
	bool m_isJumping{ false };

	float moveObjectsX; 
	float moveObjectsY;

public:

	Background();
	void setupSprite(); 
	void move(bool t_resume); 
	void checkBinds();
	void jump();
	bool rotate(sf::Sprite t_player); 

	sf::RectangleShape getBasePlatform();
	sf::RectangleShape getBoundWallL(); 
	sf::RectangleShape getBoundWallR();
	sf::CircleShape getGrapple();
	float getMoveObjectsX(); 
};