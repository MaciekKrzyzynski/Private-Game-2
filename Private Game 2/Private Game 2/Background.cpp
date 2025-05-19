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

	m_grapple.setFillColor(sf::Color::Green);
	m_grapple.setRadius(200.0f);
	m_grapple.setOrigin(200.0f, 200.0f); 
	m_grapple.setPosition({2000.0f ,350.0f});
}

void Background::move(bool t_resume)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (m_basePlatformPos.x <= 0.0f && m_basePlatformPos.x >= -1560.0f)
		{
			if (!m_launch)
			{
				m_basePlatform.move(m_speed, 0.0f);
				m_boundWallL.move(m_speed, 0.0f);
				m_boundWallR.move(m_speed, 0.0f);
				m_grapple.move(m_speed, 0.0f);
				m_basePlatformPos.x += m_speed;
			}
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (m_basePlatformPos.x <= 0.0f && m_basePlatformPos.x >= -1560.0f)
		{
			if (!m_launch)
			{
				m_basePlatform.move(-m_speed, 0.0f);
				m_boundWallL.move(-m_speed, 0.0f);
				m_boundWallR.move(-m_speed, 0.0f);
				m_grapple.move(-m_speed, 0.0f);
				m_basePlatformPos.x -= m_speed;
			}
		}
	}
	if (t_resume)
	{
		if (m_basePlatformPos.x >= 0.0f)
		{
			m_basePlatformPos.x = -2.0f; 
			m_basePlatform.setPosition(m_basePlatformPos); 
			m_boundWallL.setPosition({ -10.0f, 0.0f });
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

void Background::checkBinds()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (!m_isJumping)
		{
			m_isJumping = true;
			m_gravity.y = 0.5f; // set gravity 
		}
	}
}

void Background::jump()
{
	if (m_isJumping && !m_launch)
	{
		m_jumpHeight -= m_gravity.y; 
		m_basePlatformPos.y += m_jumpHeight; 
		m_grapple.move(0.0f, m_jumpHeight); 
		m_basePlatform.setPosition(m_basePlatformPos); 

		if (m_basePlatformPos.y < 610.0f) //prevents character from going below base platform 
		{
			m_basePlatformPos.y = 610.0f;
			m_basePlatform.setPosition(m_basePlatformPos);
			m_grapple.setPosition(m_grapple.getPosition().x, 350.0f);
			m_gravity.y = 0.00f; //sets gravity to 0 for smooth left/right movement
			m_jumpHeight = 12.0f; 
			m_isJumping = false;
		}
	}
}

bool Background::rotate(sf::Sprite t_player)
{
	m_distanceCheck = t_player.getPosition() - m_grapple.getPosition();
	m_lineLenghtCheck = (m_distanceCheck.x * m_distanceCheck.x) + (m_distanceCheck.y * m_distanceCheck.y);
	m_lineLenghtCheck = sqrt(m_lineLenghtCheck);
	m_lineLenghtCheck /= 100.0f;
	
	if (!m_launch)
	{
		m_distance = t_player.getPosition() - m_grapple.getPosition();
		m_lineLenght = (m_distance.x * m_distance.x) + (m_distance.y * m_distance.y);
		m_lineLenght = sqrt(m_lineLenght);
		m_lineLenght /= 100.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		if (m_lineLenght <= 2.06f)
		{
			m_launch = true;
		}
	}

	if (m_launch)
	{
		moveObjectsX = m_distance.x / 10; 
		moveObjectsY = m_distance.y / 10;

		if (m_basePlatform.getPosition().x > 0.0f || m_basePlatform.getPosition().x <= -1560.0f)
		{
			m_grapplePlayerTransition = true; 
			m_grapple.move(0.0f, moveObjectsY + m_grappleGravity);
			m_boundWallL.move(0.0f, moveObjectsY + m_grappleGravity);
			m_boundWallR.move(0.0f, moveObjectsY + m_grappleGravity);
		}
		else
		{
			m_grapple.move(moveObjectsX, moveObjectsY + m_grappleGravity);
			m_basePlatformPos.x += moveObjectsX;
			m_boundWallL.move(moveObjectsX, moveObjectsY + m_grappleGravity);
			m_boundWallR.move(moveObjectsX, moveObjectsY + m_grappleGravity);
		}
		m_basePlatformPos.y += moveObjectsY + m_grappleGravity;
		m_basePlatform.setPosition(m_basePlatformPos);
		
		if (m_lineLenghtCheck <= 0.2f)
		{
			m_grappleFall = true; 
		}

		if (m_grappleFall)
		{
			m_grappleGravity -= 0.5f;

			if (m_basePlatform.getPosition().y <= 610.0f) //prevents character from going below base platform 
			{
				m_basePlatformPos.y = 610.0f;
				m_basePlatform.setPosition(m_basePlatformPos);
				m_boundWallL.setPosition(m_boundWallL.getPosition().x, 0.0f); 
				m_boundWallR.setPosition(m_boundWallR.getPosition().x, 0.0f);
				m_grapple.setPosition(m_grapple.getPosition().x, 350.0f);
				m_launch = false;
				m_grappleFall = false; 
				m_grapplePlayerTransition = false; 
				m_grappleGravity = 0.0f; 
			}
		}
	}

	return m_grapplePlayerTransition; 
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

sf::CircleShape Background::getGrapple()
{
	return m_grapple;
}

float Background::getMoveObjectsX()
{
	return moveObjectsX;
}
