#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include <vector>
#include "Bullet.h"


using namespace std;
using namespace sf;
class Enemy
{
public:
	Enemy(float width, float height);
	void draw(sf::RenderWindow& window);
	void enemy1();
	void enemy2();
	void enemy3();
	void enemy4();
	void boss();


	/*void fire_bullet(float x, float y);
	void draw_bullet(sf::RenderWindow& window);
	void move_bullet();*/
	void move_enemy();
	void create_enemy();
	void erase_enemy();

	Texture texture1;
	Texture texture2;
	std::vector<pair<sf::Sprite, int>> e;
	//vector<RectangleShape> e;

	int size = e.size();
	int wave = 1;
private:
	int enemy_types[5] = { 0,1,2,3,4 };
	float enemy_1_speed = 0.3;
	float enemy_2_speed = 0.3;
	float enemy_3_speed = 0.3;
	float enemy_4_speed = 0.3;
	float boss_speed = 0.3;

	float Width;
	float Height;
	sf::Clock clock;
	sf::Time time;


};