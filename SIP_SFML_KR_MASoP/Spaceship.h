#pragma once

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Bullet.h"

class Spaceship
{
private:
	float x = 475 - 75;
	float y = 445;
	int lives = 5;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Spaceship();
	void Move();
	void Shoot(std::vector<Bullet*>&, Spaceship&);
	void Draw(sf::RenderWindow&);
	void Collision(std::vector<Enemy*>&);
	void SetLives(const int& l) { lives = l; }
	void ControlDifficulty(Bullet&, Enemy&);
	float GetX() { return x;  }
	float GetY() { return y;  }
	int GetLives() { return lives;  }
	bool Dead();
	
};