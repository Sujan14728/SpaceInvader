#include "Enemy.h"


Enemy::Enemy(float width, float height) {
	Width = width;
	Height = height;
}


void Enemy::create_enemy() {
	time = clock.getElapsedTime();
	size = e.size();
	if (time.asSeconds() > 1 && time.asSeconds() < 47) {
		if (e.size() < time.asSeconds() * 0.5 && e.size() < 8) {
			int e_number = wave;

			if (e_number > 4) {
				e_number = 4;
			}

			int e_type = (rand() % e_number);

			if (e_type == 0) {
				enemy1();
			}
			else if (e_type == 1) {
				enemy2();
			}
			else if (e_type == 2) {
				enemy3();
			}
			else if (e_type == 3) {
				enemy4();
			}
		}
	}
	if (time.asSeconds() > 50) {
		wave++;
		clock.restart();
	}
}


void Enemy::enemy1() {
	if (size == e.size()) {
		if (!texture1.loadFromFile("Texture/enemy1.jpg")) {
			cout << "Could not load player texture" << endl;
		}
		sf::Sprite en;
		en.setTexture(texture1);
		float x = rand() % ((int)Width - 5);
		float y = -1 * rand() % ((int)100);
		en.setPosition(Vector2f(x, y));
		en.setScale(Vector2f(0.06, 0.06));

		e.push_back(std::make_pair(en, 2));
	}
}


void Enemy::enemy2() {
	if (size == e.size()) {
		if (!texture2.loadFromFile("Texture/enemy2.jpg")) {
			cout << "Could not load player texture" << endl;
		}
		sf::Sprite en;
		en.setTexture(texture2);
		float x = rand() % ((int)Width - 5);
		float y = -1 * rand() % ((int)100);
		en.setPosition(Vector2f(x, y));
		en.setScale(Vector2f(0.06, 0.06));

		e.push_back(std::make_pair(en, 1));
	}
}


void Enemy::enemy3() {
	if (size == e.size()) {
		if (!texture1.loadFromFile("Texture/enemy1.jpg")) {
			cout << "Could not load player texture" << endl;
		}
		sf::Sprite en;
		en.setTexture(texture1);
		float x = rand() % ((int)Width - 5);
		float y = -1 * rand() % ((int)100);
		en.setPosition(Vector2f(x, y));
		en.setScale(Vector2f(0.08, 0.08));

		e.push_back(std::make_pair(en, 4));
	}
}

void Enemy::enemy4() {
	if (size == e.size()) {
		if (!texture2.loadFromFile("Texture/enemy2.jpg")) {
			cout << "Could not load player texture" << endl;
		}
		sf::Sprite en;
		en.setTexture(texture2);
		float x = rand() % ((int)Width - 5);
		float y = -1 * rand() % ((int)100);
		en.setPosition(Vector2f(x, y));
		en.setScale(Vector2f(0.08, 0.08));

		e.push_back(std::make_pair(en, 3));
	}
}

void Enemy::move_enemy() {
	for (int i = 0; i < e.size(); i++) {
		e[i].first.move(0, std::max((float)2,(float)(wave*0.5)));
	}
}



void Enemy::erase_enemy() {
	for (int i = 0; i < e.size(); i++) {
		if (e[i].first.getPosition().y > Height) {
			e.erase(e.begin()+i);
		}
	}
}

void Enemy::draw(sf::RenderWindow& window) {
	move_enemy();
	if (e.size() > 0 && e[0].first.getPosition().y > Height) {
		erase_enemy();
	}

	for (int i = 0; i < e.size(); i++) {
		if (e[i].second) {
			window.draw(e[i].first);
		}

	}
}
