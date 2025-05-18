#include "Player.h"

Player::Player()
{
	m_speed = 10.0f;
	m_position = { SCREEN_WIDTH / 2.0f, 610.0f };
	setupSprite();
}

void Player::setupSprite()
{
	if (!m_texture.loadFromFile("ASSETS//IMAGES//Player.png"))
	{
		std::cout << "Problem with player file" << std::endl; 
	}
	m_body.setTexture(m_texture); 
	m_body.setOrigin(25.0f, 90.0f);
	m_body.setPosition(m_position); 
}

bool Player::move(sf::RectangleShape t_base)
{
	m_resumeMove = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (t_base.getPosition().x > 0.0f)
		{
			if (m_position.x < 50.0f)
			{
				m_position.x = 50.0f;
			}
			else
			{
				m_freeRoam = true;
				m_position.x -= m_speed;
				m_body.setPosition(m_position);
			}
		}
		else if (t_base.getPosition().x <= -1560.0f)
		{
				m_freeRoam = true;
				m_position.x -= m_speed;
				m_body.setPosition(m_position);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (t_base.getPosition().x > 0.0f)
		{
			m_freeRoam = true;
			m_position.x += m_speed;
			m_body.setPosition(m_position);
		}
		else if (t_base.getPosition().x <= -1560.0f)
		{
			if (m_position.x > 1430.0f - 40.0f)
			{
				m_position.x = 1430.0f - 40.0f;
			}
			else
			{
				m_freeRoam = true;
				m_position.x += m_speed;
				m_body.setPosition(m_position);
			}
		}
	}

	if (m_freeRoam == true && m_position.x <= SCREEN_WIDTH / 2.0f + 5.0f && m_position.x >= SCREEN_WIDTH / 2.0f - 5.0f)
	{
		m_freeRoam = false; 
		m_resumeMove = true; 
	}
	return m_resumeMove; 
}

sf::Sprite Player::getBody()
{
	return m_body;
}

void Player::setBody(sf::Sprite t_body)
{
	m_body = t_body; 
}
