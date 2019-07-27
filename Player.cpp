#include "Misc.hpp"
#include "Player.hpp"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

void Player::setGraphics(sf::Color color, sf::Vector2f dimensions){

    player.setSize( dimensions );
    player.setOutlineThickness(3);
    player.setOutlineColor(color);
    player.setFillColor(color);
    Player::dimensions = dimensions;

}

void Player::jump(){

    if (!Player::inAir){

        for (int k = 100 ; k > 0 ; k--){

            Player::player.setPosition(sf::Vector2f( Player::getPos().x , Player::getPos().y + 1 ));
            Player::inAir = 1;
            sf::sleep( sf::milliseconds(10) );

        } for (int k = 100 ; k > 0 ; k--){

            Player::player.setPosition(sf::Vector2f( Player::getPos().x , Player::getPos().y - 1 ));
            sf::sleep( sf::milliseconds(10) );

        }

        if (Player::pos.y < (basePosVect.y + 30)){

            Player::pos.y = basePosVect.y + 30;
            Player::updatePos();

        }

        Player::inAir = 0;

    }
}

void Player::updatePos(){

    Player::velocity += Player::acceleration;
    Player::pos += Player::velocity;

    Player::setPos(Player::pos);

}

void Player::setPos(sf::Vector2f pos){

    Player::player.setPosition(pos);

}

void Player::setVelocity(sf::Vector2f velocity){

    Player::velocity = velocity;

}

void Player::setAcceleration(sf::Vector2f acceleration){

    Player::acceleration = acceleration;

}

sf::Vector2f Player::getVelocity(){

    return Player::velocity;

}

sf::Vector2f Player::getAcceleration(){

    return Player::acceleration;

}

sf::Vector2f Player::getPos(){

    return Player::pos;

}

void Player::createPlayer(sf::Vector2f origin){

    Player::player.setOrigin(origin);

}

sf::RectangleShape Player::returnPlayer(){

    return Player::player;

}
