#include "Enemy.h"

// накладываем текстуру на врагов 
Enemy::Enemy(const int& n)
{
	numOfEnemy = n;
	numberOfEnemies++;
	texture.loadFromFile("enemy.png");
	sprite.setTexture(texture);
}

void Enemy::AddEnemies(std::vector<Enemy*>& e)
{
	if (e.size() != 0) {
		if (e[e.size() - 1]->sprite.getPosition().y > 800)
		{
			for (int i = 0; i < difficulty; i++) {
				e.push_back(new Enemy(numberOfEnemies));
			}
		}
	}
	else
	{
		for (int i = 0; i < difficulty; i++) {
			e.push_back(new Enemy(numberOfEnemies));
		}
	}
}

void Enemy::Draw(sf::RenderWindow& w, std::vector<Enemy*> e)
{
	for (auto i : e) {
		i->sprite.setPosition(i->x, i->y);
		w.draw(i->sprite);
	}
}

void Enemy::Sort(std::vector<Enemy*>& e)
{
	Enemy* temp;

	for (int i = 0; i < e.size(); i++) {
		for (int j = i + 1; j < e.size(); j++) {
			if (e[i]->numOfEnemy < e[j]->numOfEnemy) {
				temp = e[i];
				e[i] = e[j];
				e[j] = temp;
			}
		}
	}
}

void Enemy::Move(std::vector<Enemy*>& e)
{
	for (auto i : e) {
		i->y += 1.5f;
	}
}

void Enemy::DeleteEnemies(std::vector<Enemy*>& e, Spaceship& s)
{
	for (auto i : e) {
		if (i->y > 600) {
			e.pop_back();
			s.SetLives(s.GetLives() - 1);
		}
	}
}

int Enemy::numberOfEnemies = 0;
