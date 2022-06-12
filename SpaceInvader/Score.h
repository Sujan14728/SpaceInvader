#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;
using namespace sf;

class Score
{
public:
	Vector2f Window_size;
	Score(Vector2f(window_size));
	~Score();

	void display_score(RenderWindow &window);
	void update_score(int n=1);

	void display_lives(RenderWindow &window);
	void update_lives(int n=-1);

	void display_wave(RenderWindow &window);
	void update_wave(int n = 1);

	void display_bullets(RenderWindow &window);
	void update_bullets(int n = -1);

	void Game_over(RenderWindow &window);
	void High_score();
	void draw(RenderWindow &window);
	int score = 0;
	int lives = 5;
	int wave = 1;
	int bullets = 50;
	Text text;
	Font font;
};

