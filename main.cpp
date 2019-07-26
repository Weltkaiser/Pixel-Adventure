#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "Player.hpp"
#include "Misc.hpp"

int main(){

    std::srand(static_cast<unsigned int>(std::time(NULL))); // Random initialization



//    sf::Vector2f charSize(25, 100); // Character size
    sf::Vector2f groundSize(gameWidth, 30);
    sf::Vector2f baseCoordinates( 0, -gameHeight );


    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), Title,
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true); // Window creation

//    sf::RectangleShape character; // Main character
//    character.setSize( charSize - sf::Vector2f(3, 3) );
//    character.setOutlineThickness(3);
//    character.setOutlineColor(sf::Color::Black);
//    character.setFillColor(sf::Color(100, 100, 200));
//    character.setOrigin( baseCoordinates + sf::Vector2f( 0, charSize.y + groundSize.y ) );

//    Player::Player character( charSize - sf::Vector2(3, 3), 3 );

    Player player;

    sf::RectangleShape ground; // Ground
    ground.setSize( groundSize );
    ground.setOutlineThickness(3);
    ground.setOutlineColor(sf::Color::Green);
    ground.setFillColor(sf::Color::Green);
    ground.setOrigin( basePosVect + sf::Vector2f(0, 30) );

    // Main loop

    //sf::Thread thread(&updateCharPos);
    //thread.launch();

    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)){

            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {

                window.close();
                break;

            }

        }

        window.clear(sf::Color(0, 100, 250));

        //window.draw(character);
        window.draw(ground);
        window.display();

    }

    return 0;

}
