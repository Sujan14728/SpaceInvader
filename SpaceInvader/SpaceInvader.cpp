#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <windows.h>
#include <iostream>
#include "Player.h"
#include "Score.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EBullet.h"




//  Sujan guuu


using namespace sf;
using namespace std;

int width = 600;
int height = 400;

bool collision(sf::Sprite& rect1, sf::Sprite& rect2) {
	FloatRect r1 = rect1.getGlobalBounds();
	FloatRect r2 = rect2.getGlobalBounds();
	return r1.intersects(r2);
}

int main() {
	RenderWindow window(VideoMode(width, height), "Space Invader!!");
	window.setFramerateLimit(30);
	
	int player_bullets = 50;
	
	Player player(Vector2f(window.getSize()));
	Score score(Vector2f(window.getSize()));
	
	Bullet bullet;
	EBullet e_bullet;

	Enemy enemy(width, height);

	float bullet_x;
	float bullet_y;


	while (window.isOpen()) {
		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		//player fire bullets when up key is pressed
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			bullet_x = player.player.getPosition().x + 11 ;
			bullet_y = player.player.getPosition().y -1;
			bullet.generate_bullet(window, bullet_x,bullet_y);
		}
		//Decreasing number of bullet when player fires bullet 
		for (int i = 0; i < bullet.bullet.size(); i++) {
			if (bullet.bullet[i].getPosition().y == 349) {
				score.update_bullets();
			}
		}
		
		//enemy fires bullet
		for (int i = 0; i < enemy.e.size(); i++) {
			if (i % 2 == 0 && enemy.e[i].second == 1) {
				bullet_x = enemy.e[i].first.getPosition().x + 15;
				bullet_y = enemy.e[i].first.getPosition().y + 10;
				e_bullet.generate_bullet(window,bullet_x,bullet_y);
				/*if ((int)enemy.e[i].first.getPosition().y % 100 == 0) {
				}*/
			}
		}
		//collision between enemy and player
		for (int i = 0; i < enemy.e.size(); i++) {
			if (collision(player.player, enemy.e[i].first)) {
				enemy.e.erase(enemy.e.begin()+i);
				score.update_lives();
			}
		}

		//collision between enemy and player's bullet.
		for (int i = 0; i < enemy.e.size(); i++) {
			for (int j = 0; j < bullet.bullet.size(); j++) {
				if (collision(enemy.e[i].first,bullet.bullet[j])) {

					enemy.e[i].second -= 2;
					if (enemy.e[i].second <= 0) {
						enemy.e.erase(enemy.e.begin() + i);
						bullet.bullet.erase(bullet.bullet.begin() + j);
						score.update_score();
						score.update_bullets(1);
					}
					else {
						bullet.bullet.erase(bullet.bullet.begin() + j);
					}
					
					
				}
			}
		}

		


		



		enemy.create_enemy();
		window.clear();

		bullet.draw(window);

		e_bullet.draw(window);

		player.draw(window);
		player.update();

		enemy.draw(window);

		//scoreboard
		score.draw(window);

		window.display();
	}
}