#ifndef PROJ_H
#define PROJ_H
#include <iostream>
#include <math.h>

#include <SFML/System.hpp>
#include<SFML/Graphics.hpp> 


class proj
{
private:
    //переменные
    sf::RenderWindow * window;
    sf::Event ev;
    sf::VideoMode videoMode;
    sf::Font font;
    float speed_x = 0.5;
    float speed_y = 0.5;
    std::string text;
    //блоки
    sf::RectangleShape block;
    std::vector<sf::RectangleShape> blocks;
    int maxBlock;
    float blockPosY;
    // "Пуля"
    sf::Vector2f velocity;
    float bulletSpeedX;
    float bulletSpeedY;
    bool  colision = false;
    //позиция курсора
    sf::Vector2f mousePosView;
    //объекты
    sf::RectangleShape button;
    sf::Text buttonText;
    //Платформа 
    sf::RectangleShape platform;

    sf::RectangleShape bullet;
    //приватные функции
    void initVariables();
    void initWindow();
    void setUI();
    void initBlocks();

public:
    proj(/* args */);
    ~proj();

    //функции
    void pollEvents();
    const bool running();
    void updateMousePos();
    void update();
    void updateBlocks();
    void update_button();
    void updateBullet();
    void updatePlatform();


    
    void renderBlocks();
    void render();


};



#endif