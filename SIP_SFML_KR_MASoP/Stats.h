#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Bullet.h"
#include "Spaceship.h"

struct Statistics
{
	sf::Font font;
	sf::Text text;
	sf::Clock _clock;
	sf::Time elapsed_time;

	Statistics();
	void DisplayLives(sf::RenderWindow&, Spaceship&);
	void DisplayScore(sf::RenderWindow&, Bullet&);
	void DisplayTime(sf::RenderWindow&);
	void DrawLine(sf::RenderWindow&);
	void Pause(sf::RenderWindow&);
	void PlayAgain(sf::RenderWindow&, Spaceship&, Bullet&, std::vector<Enemy*>&, std::vector<Bullet*>&);
};

