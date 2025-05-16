#include "Background.h"

Background::Background()
{
	setupSprite(); 
}

void Background::setupSprite()
{
	m_basePlatform.setFillColor(sf::Color::Black);
	m_basePlatform.setSize(m_basePlatformSize); 
	m_basePlatform.setPosition(0.0f, 610.0f);
}

sf::RectangleShape Background::getBasePlatform()
{
	return m_basePlatform;
}
