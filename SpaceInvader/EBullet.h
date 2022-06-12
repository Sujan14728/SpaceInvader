#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <vector>
using namespace sf;
using namespace std;

class EBullet
{
public:

	EBullet();
	~EBullet();
	void generate_bullet(RenderWindow& window, float x_pos, float y_pos);
	void update(RenderWindow& window);
	void draw(RenderWindow& window);
	Texture texture;
	vector <Sprite> bullet;

private:
	Clock clock;
	Time time;
};

