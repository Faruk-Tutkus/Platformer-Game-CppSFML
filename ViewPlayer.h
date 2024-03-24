#ifndef VIEWPLAYER_H
#define VIEWPLAYER_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
using namespace std;
#pragma once

class ViewPlayer
{
public:
   void InitView(sf::View*);
   void FollowPlayer(sf::View*, sf::RectangleShape*, sf::RenderWindow*);
private:
    
};

#endif