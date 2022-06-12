#include "Score.h"

Score::Score(Vector2f(window_size)) {
	Window_size = window_size;
	if (!font.loadFromFile("Fonts/times.ttf")) {
		cout << "Could not load font" << endl;
	}
	text.setFont(font);
	text.setCharacterSize(24);
	text.setPosition(Window_size.x-50, 5);
}

Score::~Score() {

}

void Score::display_score(RenderWindow &window) {
	stringstream ss;
	ss << score;

	text.setString("Score:");
	text.setCharacterSize(20);
	text.setPosition(Vector2f(Window_size.x-110, 5));
	window.draw(text);

	text.setString(ss.str());
	text.setCharacterSize(20);
	text.setPosition(Vector2f(Window_size.x-50,5));
	window.draw(text);
}
void Score::update_score(int n) {
	score = score + n;
	
}

void Score::display_lives(RenderWindow &window) {
	stringstream ss;
	ss << lives;
	
	text.setString("Lives:");
	text.setCharacterSize(18);
	text.setPosition(Vector2f(10, 5));
	window.draw(text);

	text.setString(ss.str());
	text.setCharacterSize(18);
	text.setPosition(Vector2f(65, 5));
	window.draw(text);

	if (lives == 0) {
		Game_over(window);
	}
}

void Score::update_lives(int n) {
	lives = lives + n;
}

void Score::display_wave(RenderWindow &window) {
	stringstream ss;
	ss << wave;

	text.setString("Wave:");
	text.setCharacterSize(20);
	text.setPosition(Vector2f(Window_size.x/2-100, 5));
	window.draw(text);

	text.setString(ss.str());
	text.setCharacterSize(20);
	text.setPosition(Vector2f(Window_size.x/2 - 40, 5));
	window.draw(text);
}

void Score::update_wave(int n) {
	wave = n;
}

void Score::display_bullets(RenderWindow &window) {
	stringstream ss;
	ss << bullets;

	text.setString("Bullets:");
	text.setCharacterSize(20);
	text.setPosition(Vector2f(Window_size.x / 2 + 50, 5));
	window.draw(text);

	text.setString(ss.str());
	text.setCharacterSize(20);
	text.setPosition(Vector2f(Window_size.x / 2 + 120, 5));
	window.draw(text);

	if (bullets == 0) {
		Game_over(window);
	}
}

void Score::update_bullets(int n) {
	bullets = bullets + n;
}

void Score::Game_over(RenderWindow &window) {
	window.clear();
	text.setString("Game Over!!");
	text.setCharacterSize(30);
	text.setPosition((window.getSize().x / 2) - 50, (window.getSize().y) / 2);
	window.draw(text);
	
	text.setString("Your Score is :");
	text.setCharacterSize(24);
	text.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2 + 30);
	window.draw(text);

	stringstream ss;
	ss << score;
	text.setString(ss.str());
	text.setCharacterSize(24);
	text.setPosition(window.getSize().x / 2 + 100, window.getSize().y/2 + 30);
	window.draw(text);
	window.display();
	Sleep(3000);
	window.close();
}

void Score::draw(RenderWindow &window) {
	display_score(window);
	display_lives(window);
	display_wave(window);
	display_bullets(window);
}