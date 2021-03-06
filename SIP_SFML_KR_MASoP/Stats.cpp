#include "Stats.h"

//текст на экране
Statistics::Statistics() {
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Green);
}

void Statistics::DisplayLives(sf::RenderWindow& w, Spaceship& s)
{
	text.setString("HP : " + (std::to_string(s.GetLives())));
	text.setPosition(sf::Vector2f(785, 20));
	w.draw(text);
}

void Statistics::DisplayScore(sf::RenderWindow& w, Bullet& b)
{
	text.setString("Score : " + (std::to_string(b.GetScore())));
	text.setPosition(sf::Vector2f(785, 60));
	w.draw(text);
}

//  разделительная линия между статистикой и игровой областью
void Statistics::DrawLine(sf::RenderWindow& w)
{
	for (int i = 770; i < 775; i++)
	{
		sf::VertexArray lines(sf::LinesStrip, 2);
		lines[0].position = sf::Vector2f(i, 0);
		lines[0].color = sf::Color::Green;
		lines[1].position = sf::Vector2f(i, 500);
		lines[1].color = sf::Color::Green;
		w.draw(lines);
	}
}

void Statistics::Pause(sf::RenderWindow& w)
{
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			elapsed_time += _clock.getElapsedTime();
			while (true)
			{
				text.setString("Press 'R' to resume");
				text.setPosition(sf::Vector2f(325, 250));
				w.draw(text);
				w.display();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
					break;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					exit(0);
			}
			_clock.restart();
		}
	}
}

void Statistics::PlayAgain(sf::RenderWindow& w, Spaceship& s, Bullet& b, std::vector<Enemy*>& e, std::vector<Bullet*>& bu)
{
	if (s.Dead()) {
		while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::R))) {
			w.clear(sf::Color::Black);
			text.setString("Press 'R' to play again.\nPress 'Esc' to quit.");
			text.setPosition(sf::Vector2f(325, 230));
			w.draw(text);
			w.display();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				exit(0);

			s.SetLives(5);
			b.SetScore(0);
			e.clear();
			bu.clear();
			_clock.restart();
		}
	}
}

void Statistics::DisplayTime(sf::RenderWindow& w)
{
	std::string time = std::to_string(_clock.getElapsedTime().asSeconds() + elapsed_time.asSeconds());
	for (int i = 0; i < 5; i++) { time.pop_back(); }
	text.setString("Time : " + time);
	text.setPosition(sf::Vector2f(785, 450));
	w.draw(text);
}
