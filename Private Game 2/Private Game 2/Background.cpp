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

	m_boundWallL.setFillColor(sf::Color::Black);
	m_boundWallL.setSize({ 20.0f,SCREEN_HEIGHT });
	m_boundWallL.setPosition({ -20.0f, 0.0f }); 

	m_boundWallR.setFillColor(sf::Color::Black);
	m_boundWallR.setSize({ 20.0f,SCREEN_HEIGHT });
	m_boundWallR.setPosition({2980.0f, 0.0f });
}

void Background::move(bool t_resume)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (m_basePlatformPos.x <= 0.0f && m_basePlatformPos.x >= -1560.0f)
		{
			m_basePlatform.move(m_speed, 0.0f);
			m_boundWallL.move(m_speed, 0.0f);
			m_boundWallR.move(m_speed, 0.0f);
			m_basePlatformPos.x += m_speed;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (m_basePlatformPos.x <= 0.0f && m_basePlatformPos.x >= -1560.0f)
		{
			m_basePlatform.move(-m_speed, 0.0f);
			m_boundWallL.move(-m_speed, 0.0f);
			m_boundWallR.move(-m_speed, 0.0f);
			m_basePlatformPos.x -= m_speed;
		}
	}
	if (t_resume)
	{
		if (m_basePlatformPos.x >= 0.0f)
		{
			m_basePlatformPos.x = -2.0f; 
			m_basePlatform.setPosition(m_basePlatformPos); 
			m_boundWallL.setPosition({ -20.0f, 0.0f });
			m_boundWallR.setPosition({ 3000.0f - 20.0f, 0.0f });
		}
		else if (m_basePlatformPos.x <= -1560.0f)
		{
			m_basePlatformPos.x = -1558.0f;
			m_basePlatform.setPosition(m_basePlatformPos);
			m_boundWallR.setPosition({SCREEN_WIDTH - 10.0f, 0.0f});
			m_boundWallL.setPosition({ -1560.0f, 0.0f });
		}
	}
}

sf::RectangleShape Background::getBasePlatform()
{
	return m_basePlatform;
}

sf::RectangleShape Background::getBoundWallL()
{
	return m_boundWallL;
}

sf::RectangleShape Background::getBoundWallR()
{
	return m_boundWallR;
}
