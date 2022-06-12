#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <vector>

using namespace sf;
using namespace std;

class Bullet
{
public:
	Texture texture;
	Bullet();
	~Bullet();
	void generate_bullet(RenderWindow &window,float x_pos, float y_pos);
	void update(RenderWindow &window);
	void draw(RenderWindow &window);
	vector <Sprite> bullet;
private:
	Clock clock;
	Time time;
};

