#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "Misc.hpp"

class Player
{

public:
    void setGraphics(sf::Color color, sf::Vector2f dimensions);
    void updatePos();
    void setPos(sf::Vector2f pos);
    void setVelocity(sf::Vector2f velocity);
    void setAcceleration(sf::Vector2f acceleration);
    sf::Vector2f getVelocity();
    sf::Vector2f getAcceleration();
    sf::Vector2f getPos();
    void createPlayer(sf::Vector2f origin);
    sf::RectangleShape returnPlayer();

private:
    sf::RectangleShape player;
    sf::Vector2f pos;
    sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
    sf::Vector2f acceleration = sf::Vector2f(0.f, 0.f);
    sf::Vector2f dimensions;
    sf::Vector2f origin;

};

#endif
