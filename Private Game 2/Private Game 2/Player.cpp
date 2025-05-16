#include "Player.h"

Player::Player()
{
	setupSprite();
}

void Player::setupSprite()
{
	m_body.setFillColor(sf::Color::Red);
	m_body.setSize({ 50.0f, 90.0f });
	m_body.setOrigin(25.0f, 90.0f);
	m_body.setPosition(SCREEN_WIDTH / 2.0f, 610.0f); 
}

sf::RectangleShape Player::getBody()
{
	return m_body;
}
