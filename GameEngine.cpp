#include "GameEngine.h"
GameEngine::GameEngine()
{
    WindowVariable();
    Player::InitHitBoxPlayer(&hitBoxPlayer);
    Map::InitMap();
    Map::InitCollision(&collision);
    Map::PrintCollision(&collision,&collisions,arr);
    Player::InitNextPosCollision(&hitBoxPlayer,&nextBox);
    ViewPlayer::InitView(&view);
    rect_PlayerIdle.left = 0;
    rect_PlayerRun.left = 0;
    s_Player.setScale(4.25f, 4.25f);
    UpdateWindow();
}
void GameEngine::WindowVariable(){
    window = new sf::RenderWindow(sf::VideoMode(1280,720), "SFML");
    event = new sf::Event;
    this->window->setFramerateLimit(75);
    this->window->setVerticalSyncEnabled(true);
}
void GameEngine::UpdateWindow(){
    while (this->window->isOpen())
    {
        UpdateEvent();
        Player::MovePlayer(&hitBoxPlayer,&op,&s_Player,&velocity,&jumpable,&inAir);
        Player::NextPosCollision(&nextPos,&nextBox,&hitBoxPlayer,&collisions,&velocity,&jumpable);
        Player::UnifiedHitBoxAndimation(&hitBoxPlayer,&s_Player);
        ViewPlayer::FollowPlayer(&view,&hitBoxPlayer,window);
        AnimationTime();
        RenderWindow();
    }
}
void GameEngine::UpdateEvent(){
    while (this->window->pollEvent(*this->event))
    {
        switch (this->event->type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                this->window->close();
        break;
        }   
    }
}
void GameEngine::RenderWindow(){
    this->window->clear();
    this->window->draw(s_Player);
    this->window->draw(hitBoxPlayer);
    Map::PrintMap(window, arr);
    this->window->draw(nextBox);
    for (auto &i : collisions)
    {
        this->window->draw(i);
    }
    this->window->display();
}
void GameEngine::AnimationTime(){
    if (timeAnimation >= timeMaxAnimation)
    {
        timeAnimation = 0.f;
        Player::UpdateAnimationPlayer(&t_Player,&rect_PlayerIdle,&rect_PlayerRun,&s_Player,animationName,&op);
    }
    else
        timeAnimation += 25.f;
}