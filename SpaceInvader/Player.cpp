#include "Player.h"

Player::Player(Vector2f(window_size)) {
	Window_size = window_size;
	create_player();
}

Player::~Player() {

}

void Player::create_player() {
	if (!texture.loadFromFile("Texture/player_img.jfif")) {
		cout << "Could not load player texture"<<endl;
	}

	player.setTexture(texture);
	player.setPosition(Vector2f(Window_size.x/2-10, Window_size.y-50));
	player.setScale(Vector2f(0.25, 0.25));
}

void Player::move_player() {
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (player.getPosition().x < Window_size.x-30) {
				player.move(5, 0);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			if (player.getPosition().x > 0) {
				player.move(-5, 0);
			}
		}
}

void Player::update() {
	move_player();
}

void Player::draw(RenderWindow &window) {
	window.draw(player);
}