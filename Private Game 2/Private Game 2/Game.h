/// <summary>
/// author Pete Lowe May 2022
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>


#include "SFML/Window.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Event.hpp"
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Player.h"
#include "Background.h"

class Game
{
public:
	Game();
	~Game();
	Player m_player;
	Background m_background; 
	bool m_resumeBackground{ false };
	bool m_grapplePlayerTransition{ false };
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

