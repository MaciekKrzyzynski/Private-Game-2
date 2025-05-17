#include "Background.h"

Background::Background()
{
	m_speed = 10.0f;
	setupSprite(); 
}

void Background::setupSprite()
{
	m_basePlatform.setFillColor(sf::Color::Black);
	m_basePlatform.setSize(m_basePlatformSize); 
	m_basePlatform.setPosition(m_basePlatformPos);
}

void Background::move(bool t_resume)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (m_basePlatformPos.x <= 0.0f && m_basePlatformPos.x >= -1560.0f)
		{
			m_basePlatform.move(m_speed, 0.0f);
			m_basePlatformPos.x += m_speed;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (m_basePlatformPos.x <= 0.0f && m_basePlatformPos.x >= -1560.0f)
		{
			m_basePlatform.move(-m_speed, 0.0f);
			m_basePlatformPos.x -= m_speed;
		}
	}
	if (t_resume)
	{
		if (m_basePlatformPos.x >= 0.0f)
		{
			m_basePlatformPos.x = -2.0f; 
			m_basePlatform.setPosition(m_basePlatformPos); 
		}
		else if (m_basePlatformPos.x <= -1560.0f)
		{
			m_basePlatformPos.x = -1558.0f;
			m_basePlatform.setPosition(m_basePlatformPos);
		}
	}
}

sf::RectangleShape Background::getBasePlatform()
{
	return m_basePlatform;
}
