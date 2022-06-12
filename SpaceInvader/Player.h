#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

class Player
{
public:
	Texture texture;
	Sprite player;
	Vector2f Window_size;
	Player(Vector2f(window_size));
	~Player();
	
	void create_player();
	void move_player();
	
	void update();
	void draw(RenderWindow &window);

};
