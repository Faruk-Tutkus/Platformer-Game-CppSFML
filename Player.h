#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<vector>
using namespace std;
#pragma once
class Player
{
public:
    void InitHitBoxPlayer(sf::RectangleShape*);
    void UpdateAnimationPlayer(sf::Texture*,sf::IntRect*,sf::IntRect*,sf::Sprite*,string[],int*);
    void UnifiedHitBoxAndimation(sf::RectangleShape*, sf::Sprite*);
    void MovePlayer(sf::RectangleShape*,int*, sf::Sprite*, sf::Vector2f*,bool*,bool*);
    void InitNextPosCollision(sf::RectangleShape*, sf::RectangleShape*);
    void NextPosCollision(sf::FloatRect*, sf::RectangleShape*, sf::RectangleShape*, vector<sf::RectangleShape>*, sf::Vector2f*, bool*);
protected:
    int maxIdle = (10 * 32);
    int idlePlus = (1 * 32);

    int maxRun = (11 * 32);
    int runPlus = (1 * 32);

    float moveSpeed = 5.f;

    float timeGravity = 0.f;
    float timeMaxGravity = 10.f;

    float timeAir = 0.f;
    float timeMaxAir = 15.f;

    float scaleX = 4.25f;
    float scaleY = 4.25f;
};
#endif