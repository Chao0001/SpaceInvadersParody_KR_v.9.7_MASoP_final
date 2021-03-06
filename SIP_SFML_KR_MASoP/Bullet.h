#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"

class Bullet
{
private:
	float x, y;
	int score = 0;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Bullet(const float&, const float&);
	void Draw(sf::RenderWindow&, std::vector<Bullet*>&);
	void Move(std::vector<Bullet*>&);
	void DeleteBullets(std::vector<Bullet*>&);
	void Collision(std::vector<Bullet*>&, std::vector<Enemy*>&);
	void SetScore(const int& s) { score = s; }
	float GetY() { return y; };
	int GetScore() { return score;  }
};
