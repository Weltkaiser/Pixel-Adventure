#ifndef MISC_HPP
#define MISC_HPP

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

const int gameWidth = 800;
const int gameHeight = 600;

const float gravity(5.f);

const std::string Title = "Pixel Adventure";

const sf::Vector2f basePosVect( 0, -gameHeight );


#endif // MISC_HPP
