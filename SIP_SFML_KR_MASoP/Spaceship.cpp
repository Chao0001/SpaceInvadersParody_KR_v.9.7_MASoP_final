#include "Spaceship.h"

// накладываем текстуру на игрока
Spaceship::Spaceship()
{
	texture.loadFromFile("player.png");
	sprite.setTexture(texture);
}


//движение игрока
void Spaceship::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && 0.0 < x) {
		x -= 6.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && x < 769.0 - 75.0) {
		x += 6.0f;
	}
}


//выстрел
void Spaceship::Shoot(std::vector<Bullet*>& b, Spaceship& s)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (b.size() > 0) {
			if (b[b.size() - 1]->GetY() < 300) {
				b.push_back(new Bullet(s.x + 36, s.y));
			}
		}
		else {
			b.push_back(new Bullet(s.x + 36, s.y));
		}
	}
}

void Spaceship::Draw(sf::RenderWindow& w)
{
	sprite.setPosition(x, y);
	w.draw(sprite);
}

// касание врагом игрока
void Spaceship::Collision(std::vector<Enemy*>& e)
{
	sf::FloatRect rect(x, y, 75.0f, 52.0f);
	for (int i = 0; i < e.size(); i++) {
		sf::FloatRect eRect((e[i])->GetX(), (e[i])->GetY(), 50, 56);

		if (rect.intersects(eRect))
		{
			lives--;
			e.erase(e.begin() + i);
			return;
		}
	}
}

bool Spaceship::Dead()
{
	if (lives <= 0)
		return true;
	return false;
}


//сложность
void Spaceship::ControlDifficulty(Bullet& b, Enemy& e)
{
	if (b.GetScore() < 40)
		e.SetDifficulty(2);
	else
	{
		e.SetDifficulty(b.GetScore() / 20);
	}
}
