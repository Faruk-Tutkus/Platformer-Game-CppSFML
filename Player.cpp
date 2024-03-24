#include "Player.h"
void Player::InitHitBoxPlayer(sf::RectangleShape* hitBoxPlayer){
    hitBoxPlayer->setFillColor(sf::Color(255,255,255,50));
    hitBoxPlayer->setSize(sf::Vector2f(100.f,120.f));
    hitBoxPlayer->setPosition(100.f, -250.f);
}
void Player::UpdateAnimationPlayer(sf::Texture* t_Player,sf::IntRect* rect_PlayerIdle,
sf::IntRect* rect_PlayerRun,sf::Sprite* s_Player,string animationName[],int* op){
    switch (*op)
    {
    case 0:
        t_Player->loadFromFile(animationName[0]);
        rect_PlayerIdle->height = 32;
        rect_PlayerIdle->width = 32;
        if (rect_PlayerIdle->left != maxIdle)
        {
            rect_PlayerIdle->left += idlePlus;
        }
        else
            rect_PlayerIdle->left = (0 * 32);
        s_Player->setOrigin(rect_PlayerIdle->width / 2, rect_PlayerIdle->height / 2);
        s_Player->setTextureRect(*rect_PlayerIdle);
        s_Player->setTexture(*t_Player);
        break;
    case 1:
        t_Player->loadFromFile(animationName[1]);
        rect_PlayerRun->height = 32;
        rect_PlayerRun->width = 32;
        if (rect_PlayerRun->left != maxRun)
        {
            rect_PlayerRun->left += runPlus;
        }
        else
            rect_PlayerRun->left = (0 * 32);
        s_Player->setScale(scaleX,scaleY);
        s_Player->setOrigin(rect_PlayerRun->width / 2, rect_PlayerRun->height / 2);
        s_Player->setTextureRect(*rect_PlayerRun);
        s_Player->setTexture(*t_Player);
        break;
    case 2:
        t_Player->loadFromFile(animationName[1]);
        rect_PlayerRun->height = 32;
        rect_PlayerRun->width = 32;
        if (rect_PlayerRun->left != maxRun)
        {
            rect_PlayerRun->left += runPlus;
        }
        else
            rect_PlayerRun->left = (0 * 32);
        s_Player->setScale(-scaleX,scaleY);
        s_Player->setOrigin(rect_PlayerRun->width / 2, rect_PlayerRun->height / 2);
        s_Player->setTextureRect(*rect_PlayerRun);
        s_Player->setTexture(*t_Player);
        break;
    }
}
void Player::UnifiedHitBoxAndimation(sf::RectangleShape*hitBoxPlayer, sf::Sprite* s_Player){
    s_Player->setPosition(hitBoxPlayer->getPosition().x + hitBoxPlayer->getSize().x / 2, hitBoxPlayer->getPosition().y + hitBoxPlayer->getSize().y / 2 - 7.5f);
}
void Player::MovePlayer(sf::RectangleShape* hitBoxPlayer,int* op,sf::Sprite* s_Player,
sf::Vector2f* velocity,bool* jumpable, bool* inAir){
    velocity->x = 0.f;
    if (timeGravity >= timeMaxGravity)
    {
        timeGravity = 0.f;
        velocity->y = 10;
    }
    else
        timeGravity += 2.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && *jumpable && *inAir == false)
    {
        *jumpable = false;
        *inAir = true;
    }
    if (*inAir)
    {
        velocity->y = -20;
        if (timeAir >= timeMaxAir)
        {
            timeAir = 0.f;
            velocity->y = 0;
            *inAir = false;
        }
        else{
            timeAir += 1.f;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        (*op) = 1;
        velocity->x = moveSpeed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        (*op) = 2;
        velocity->x = -moveSpeed;
    }
    else
        (*op) = 0; 

}
void Player::InitNextPosCollision(sf::RectangleShape* hitBoxPlayer, sf::RectangleShape* nextBox){
    
    nextBox->setFillColor(sf::Color::Transparent);
    nextBox->setOutlineColor(sf::Color::Green);
    nextBox->setOutlineThickness(1.f);
}
void Player::NextPosCollision(sf::FloatRect* nextPos, sf::RectangleShape* nextBox, sf::RectangleShape* hitBoxPlayer,
vector<sf::RectangleShape>* collisions, sf::Vector2f* velocity, bool* jumpable){
    *jumpable = false;
    for (auto &i : *collisions)
    {
        nextBox->setSize(hitBoxPlayer->getSize());
        sf::FloatRect playerBounds = hitBoxPlayer->getGlobalBounds();
        sf::FloatRect wallBounds = i.getGlobalBounds();
        (*nextPos) = playerBounds;
        nextPos->left += velocity->x;
        nextPos->top += velocity->y; 
        nextBox->setPosition(nextPos->left, nextPos->top);
        if (wallBounds.intersects(*nextPos))
        {
            //bottom
            if (playerBounds.top <= wallBounds.top
                && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left)
            {
                velocity->y = 0.f;
                hitBoxPlayer->setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
                *jumpable = true;
            }
            //top
            else if (playerBounds.top > wallBounds.top
                && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left)
            {
                velocity->y = 0.f;
                hitBoxPlayer->setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
            }
            
            //right
            if (playerBounds.left < wallBounds.left
                && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
                && playerBounds.top < wallBounds.top + wallBounds.height
                && playerBounds.top + playerBounds.height > wallBounds.top)
            {
                velocity->x = 0.f;
                hitBoxPlayer->setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
            }
            //left
            else if (playerBounds.left > wallBounds.left
                && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
                && playerBounds.top < wallBounds.top + wallBounds.height
                && playerBounds.top + playerBounds.height > wallBounds.top)
            {
                velocity->x = 0.f;
                hitBoxPlayer->setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
            }
        }
    }
    hitBoxPlayer->move(*velocity);
}