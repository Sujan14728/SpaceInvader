#include "./Bullet.h"

Bullet::Bullet() {
	
}

Bullet::~Bullet() {
}

void Bullet::generate_bullet(RenderWindow &window,float x_pos,float y_pos) {
	time = clock.getElapsedTime();
	if (time.asMilliseconds() >= 200) {
		if (!texture.loadFromFile("Texture/bullet3.jfif")) {
			cout << "Could not load player texture" << endl;
		}
		Sprite last;
		last.setTexture(texture);
		//last.setPosition(Vector2f(window.getSize().x / 2 - 10, window.getSize().y - 50));
		last.setScale(Vector2f(0.2, 0.1));
		//last.setSize(Vector2f(3, 10));
		last.setPosition(Vector2f(x_pos, y_pos));
		//No. of bullets on the screen
		if (bullet.size() <= 10) {
			bullet.push_back(last);
		}
		clock.restart();
	}
}

void Bullet::update(RenderWindow &window) {	
	for (int i = 0; i < bullet.size(); i++) {
		bullet[i].move(0, -5);
		if (bullet[i].getPosition().y < -10) {
			bullet.erase(bullet.begin()+i);
		}
	}
}
void Bullet::draw(RenderWindow &window) {
	update(window);
	for (int i = 0; i < bullet.size(); i++) {
		window.draw(bullet[i]);
	}
}