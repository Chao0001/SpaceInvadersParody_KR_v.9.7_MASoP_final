//������� Space Invaders �� SFML �� ����� C++
//SFML 2.5.1 �������������� ����� ��������� ������� NuGet
//������������� MS Visual Studio 2019, ����� ������������ Visual Studio 2017 v.141, SDK 10.0.18362.0

#include <SFML/Graphics.hpp>
#include "classes.h"
#include <sstream>

std::vector<Enemy*> enemies;
std::vector<Bullet*> bullets;

sf::RenderWindow window(sf::VideoMode(950, 500), "Space Invaders", sf::Style::Close);

#include "Enemy.h"
#include "Bullet.h"
#include "Spaceship.h"
#include "Stats.h"

int main()
{
	sf::Event event;
	window.setFramerateLimit(60);

	Enemy enemy(0);
	Bullet bullet(0.0, 0.0);
	Spaceship spaceship;
	Statistics stats;

	sf::Texture textureBackground;
	textureBackground.loadFromFile("background.png");
	sf::Sprite spriteBackground;

	while (window.isOpen())
	{
		srand(time(0));

		//���
		spriteBackground.setTexture(textureBackground);
		spriteBackground.setPosition(0, 0);

		window.clear();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				exit(0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				exit(0);
		}
		//���
		window.draw(spriteBackground);

		//�����
		spaceship.Move();
		spaceship.Shoot(bullets, spaceship);
		spaceship.Draw(window);
		spaceship.Collision(enemies);
		spaceship.ControlDifficulty(bullet, enemy);
		spaceship.Dead();
		stats.PlayAgain(window, spaceship, bullet, enemies, bullets);

		// ���������
		enemy.AddEnemies(enemies);
		enemy.Draw(window, enemies);
		enemy.Move(enemies);
		enemy.DeleteEnemies(enemies, spaceship);

		// ����
		bullet.Draw(window, bullets);
		bullet.Move(bullets);
		bullet.DeleteBullets(bullets);
		bullet.Collision(bullets, enemies);

		// ���������� � �����
		stats.DrawLine(window);
		stats.DisplayLives(window, spaceship);
		stats.DisplayScore(window, bullet);
		stats.DisplayTime(window);
		stats.Pause(window);




		window.display();
	}
}

