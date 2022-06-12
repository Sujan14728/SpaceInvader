#include "EBullet.h"

EBullet::EBullet() {

}

EBullet::~EBullet() {

}

void EBullet::generate_bullet(RenderWindow& window, float x_pos, float y_pos) {
	time = clock.getElapsedTime();
	if (time.asMilliseconds() >= 2000) {
		if (!texture.loadFromFile("Texture/bullet3.jfif")) {
			cout << "Could not load player texture" << endl;
		}
		Sprite last;
		last.setTexture(texture);
		last.setScale(Vector2f(0.2, 0.1));
		last.setPosition(Vector2f(x_pos, y_pos));
		bullet.push_back(last);
		clock.restart();
	}
}

void EBullet::update(RenderWindow& window) {
	for (int i = 0; i < bullet.size(); i++) {
		bullet[i].move(0, 10);
		if (bullet[i].getPosition().y > window.getSize().y) {
			bullet.erase(bullet.begin() + i);
		}
	}
}

void EBullet::draw(RenderWindow& window) {
	update(window);
	for (int i = 0; i < bullet.size(); i++) {
		if (bullet[i].getPosition().y > 50) {
			window.draw(bullet[i]);
		}
	}
}