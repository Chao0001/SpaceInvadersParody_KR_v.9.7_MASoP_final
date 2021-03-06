#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "classes.h"
#include "Spaceship.h"

class Enemy
{
private:
	static int numberOfEnemies;
	float x = (rand() % 700);
	float y = (rand() % 50) - 100;
	int numOfEnemy;
	int difficulty = 2;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Enemy(const int&);
	void AddEnemies(std::vector<Enemy*>&);
	void Draw(sf::RenderWindow&, std::vector<Enemy*>);
	void Sort(std::vector<Enemy*>&);
	void Move(std::vector<Enemy*>&);
	void DeleteEnemies(std::vector<Enemy*>&, Spaceship&);
	void SetDifficulty(const int& d) { difficulty = d; };
	float GetX() { return x;  }
	float GetY() { return y;  }
};