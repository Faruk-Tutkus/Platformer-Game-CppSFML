#include "Map.h"
void Map::InitMap(){
    t_Map.loadFromFile("Terrain (16x16).png");
    s_Map.setTexture(t_Map);
    IntRect();
}
void Map::IntRect(){
    empty_0.height = 16;
    empty_0.width = 0;
    empty_0.left = 48;
    empty_0.top = 32;

    grass_1.height = 16;
    grass_1.width = 16;
    grass_1.left = 0;
    grass_1.top = 0;

    grass_2.height = 16;
    grass_2.width = 16;
    grass_2.left = 16;
    grass_2.top = 0;

    grass_3.height = 16;
    grass_3.width = 16;
    grass_3.left = 32;
    grass_3.top = 0;

    soil_4.height = 16;
    soil_4.width = 16;
    soil_4.left = 0;
    soil_4.top = 16;

    soil_5.height = 16;
    soil_5.width = 16;
    soil_5.left = 16;
    soil_5.top = 16;

    soil_6.height = 16;
    soil_6.width = 16;
    soil_6.left = 32;
    soil_6.top = 16;

    soilDeep_7.height = 16;
    soilDeep_7.width = 16;
    soilDeep_7.left = 0;
    soilDeep_7.top = 32;

    soilDeep_8.height = 16;
    soilDeep_8.width = 16;
    soilDeep_8.left = 16;
    soilDeep_8.top = 32;

    soilDeep_9.height = 16;
    soilDeep_9.width = 16;
    soilDeep_9.left = 32;
    soilDeep_9.top = 32;

    copper_10.height = 16;
    copper_10.width = 16;
    copper_10.left = 48;
    copper_10.top = 0;

    copper_11.height = 16;
    copper_11.width = 16;
    copper_11.left = 64;
    copper_11.top = 0;

    copper_12.height = 16;
    copper_12.width = 16;
    copper_12.left = 80;
    copper_12.top = 0;

    copperBlock_13.height = 16;
    copperBlock_13.width = 16;
    copperBlock_13.left = 64;
    copperBlock_13.top = 16;

    copperBlock_14.height = 16;
    copperBlock_14.width = 16;
    copperBlock_14.left = 80;
    copperBlock_14.top = 16;

    copperBlock_15.height = 16;
    copperBlock_15.width = 16;
    copperBlock_15.left = 64;
    copperBlock_15.top = 32;

    copperBlock_16.height = 16;
    copperBlock_16.width = 16;
    copperBlock_16.left = 80;
    copperBlock_16.top = 32;

}
void Map::PrintMap(sf::RenderWindow* window, int arr[SIZE_X][SIZE_Y]){
    sf::IntRect tempRect;
    for (int i = 0; i < SIZE_X; i++)
    {
        for (int j = 0; j < SIZE_Y; j++)
        {
            switch (arr[j][i])
            {
            case 0:
                tempRect = empty_0;
                break;
            case 1:
                tempRect = grass_1;
                break;
            case 2:
                tempRect = grass_2;
                break;
            case 3:
                tempRect = grass_3;
                break;
            case 4:
                tempRect = soil_4;
                break;
            case 5:
                tempRect = soil_5;
                break;
            case 6:
                tempRect = soil_6;
                break;
            case 7:
                tempRect = soilDeep_7;
                break;
            case 8:
                tempRect = soilDeep_8;
                break;
            case 9:
                tempRect = soilDeep_9;
                break;
            case 10:
                tempRect = copper_10;
                break;
            case 11:
                tempRect = copper_11;
                break;
            case 12:
                tempRect = copper_12;
                break;
            case 13:
                tempRect = copperBlock_13;
                break;
            case 14:
                tempRect = copperBlock_14;
                break;
            case 15:
                tempRect = copperBlock_15;
                break;
            case 16:
                tempRect = copperBlock_16;
                break;
            }
            s_Map.setTextureRect(tempRect);
            s_Map.setScale(7.5f,7.5f);
            s_Map.setPosition((i * 16 * 7.5), (j * 16 * 7.5));
            window->draw(s_Map);
        }
    }
}
void Map::InitCollision(sf::RectangleShape* collision){
    collision->setFillColor(sf::Color(255,0,0,100));
    collision->setSize(sf::Vector2f((16 * 7.5),(16 * 7.5)));
}
void Map::PrintCollision(sf::RectangleShape* collision, vector<sf::RectangleShape>* collisions, int arr[SIZE_X][SIZE_Y]){
    for (int i = 0; i < SIZE_X; i++)
    {
        for (int j = 0; j < SIZE_Y; j++)
        {
            if (arr[j][i] != 0)
            {
                collisions->push_back(*collision);
                (*collisions).back().setPosition((i * 16 * 7.5), (j * 16 * 7.5));
            }
        }
    } 
}