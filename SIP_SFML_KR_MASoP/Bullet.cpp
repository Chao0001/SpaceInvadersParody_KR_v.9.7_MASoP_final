#include "Bullet.h"

// накладываем текстуру на пулю
Bullet::Bullet(const float& a, const float& b) : x(a), y(b)
{
	texture.loadFromFile("bullet.png");
	sprite.setTexture(texture);
}

void Bullet::Draw(sf::RenderWindow& w, std::vector<Bullet*>& b)
{
	for (auto i : b) {
		(i->sprite).setPosition(i->x, i->y);
		w.draw(i->sprite);
	}
}

void Bullet::Move(std::vector<Bullet*>& b)
{
	for (auto i : b) {
		i->y -= 7.0f;
	}
}

void Bullet::DeleteBullets(std::vector<Bullet*>& b)
{
	for (std::vector<Bullet*>::iterator it = b.begin(); it != b.end(); it++) {
		if ((*it)->y < -50)
			b.erase(it);
		break;
	}
}

void Bullet::Collision(std::vector<Bullet*>& b, std::vector<Enemy*>& e)
{
	for (int i = 0; i < e.size(); i++) {
		sf::FloatRect eRect((e[i])->GetX(), (e[i])->GetY(), 50, 56);
		for (int j = 0; j < b.size(); j++) {
			sf::FloatRect bRect((b[j])->sprite.getPosition().x, (b[j])->sprite.getPosition().y, 5, 30);
			if (eRect.intersects(bRect))
			{
				e.erase(e.begin() + i);
				b.erase(b.begin() + j);
				score++;
				return;
			}
		}
	}
}