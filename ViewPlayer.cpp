#include "ViewPlayer.h"
void ViewPlayer::InitView(sf::View* view){
    view->setSize(1280,720);
}
void ViewPlayer::FollowPlayer(sf::View* view, sf::RectangleShape* hitBoxPlayer, sf::RenderWindow* window){
    view->setCenter(hitBoxPlayer->getPosition());
    window->setView(*view);
}