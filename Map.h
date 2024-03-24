#ifndef MAP_H
#define MAP_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
using namespace std;
#pragma once
#define SIZE_X 75
#define SIZE_Y 75
class Map
{
public:
    void InitMap();
	void PrintMap(sf::RenderWindow*, int[SIZE_X][SIZE_Y]);
    void InitCollision(sf::RectangleShape*);
    void PrintCollision(sf::RectangleShape*, vector<sf::RectangleShape>*, int[SIZE_X][SIZE_Y]);
    void IntRect();
protected:
    
    sf::Texture t_Map;
    sf::Sprite s_Map;

    sf::IntRect empty_0;

    sf::IntRect grass_1;
    sf::IntRect grass_2;
    sf::IntRect grass_3;

    sf::IntRect soil_4;
    sf::IntRect soil_5;
    sf::IntRect soil_6;

    sf::IntRect soilDeep_7;
    sf::IntRect soilDeep_8;
    sf::IntRect soilDeep_9;

    sf::IntRect copper_10;
    sf::IntRect copper_11;
    sf::IntRect copper_12;
    sf::IntRect copperBlock_13;
    sf::IntRect copperBlock_14;
    sf::IntRect copperBlock_15;
    sf::IntRect copperBlock_16;
};

#endif