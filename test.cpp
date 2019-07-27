#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int signnum(int x){

    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;

}

int main(){

    const float gravity(10.f);
    const sf::Vector2f playerSize(25, 100);
    const int gameWidth(800);
    const int gameHeight(600);
    const sf::Vector2f groundSize(gameWidth, 50);
    const sf::Vector2f baseCoordinates(0, -gameHeight);
    const std::string Title("Pixel Adventure");
    const int groundHeight( baseCoordinates.y + groundSize.y );

    bool collideGround(false);
    int playerFeetPos;

    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), Title,
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    sf::RectangleShape ground;
    ground.setSize( groundSize );
    ground.setOutlineThickness(1);
    ground.setOutlineColor(sf::Color::Transparent);
    ground.setFillColor(sf::Color::Green);
    ground.setOrigin(baseCoordinates + sf::Vector2f(0, groundSize.y));

    sf::RectangleShape player;
    player.setSize(playerSize);
    player.setOutlineThickness(1);
    player.setOutlineColor(sf::Color::Transparent);
    player.setFillColor(sf::Color::Red);
    player.setOrigin(baseCoordinates + sf::Vector2f(-25.f, groundSize.y + playerSize.y + 125.f));

    float playerPosX = baseCoordinates.x + 25.f;
    float playerPosY = baseCoordinates.y + groundSize.y + playerSize.y + 125.f;

    float playerVelocityY(0);
    float playerVelocityX(0);

    std::cout << "Origin player : (" << playerPosX << ", " << playerPosY << ")" << std::endl;

    while (window.isOpen()){

        std::cout << "Player position : (" << playerPosX << ", " << playerPosY << ")" << std::endl;
        std::cout << "Colliding : " << collideGround << std::endl;

        sf::FloatRect playerBox = player.getGlobalBounds();
        sf::FloatRect groundBox = ground.getGlobalBounds();

        playerFeetPos = playerPosY - playerSize.y;

        if ( playerBox.intersects( groundBox ) ){

            collideGround = true;

        } else { collideGround = false; }

        sf::Event event;

        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed){
                window.close();
                break;

            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left)){

                playerVelocityX--;

            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right)){

                playerVelocityX++;

            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)){

                playerVelocityY += 10;

            }

        }

        if (playerVelocityY != 0 && playerVelocityX == 0){

            player.move( sf::Vector2f(0.f, -gravity) );
            playerPosY += gravity;
            playerVelocityY--;
            collideGround = true;

        }

        if (playerVelocityX != 0 && playerVelocityY == 0){


            player.move( sf::Vector2f( signnum(playerVelocityX)*10.f, 0.f) );
            playerPosX += signnum(playerVelocityX)*10;
            playerVelocityX -= signnum(playerVelocityX);

        }

        if (playerVelocityX != 0 && playerVelocityY != 0){

            player.move( sf::Vector2f( signnum(playerVelocityX)*10.f, -gravity) );
            playerPosX += signnum(playerVelocityX)*10;
            playerPosY += gravity;
            collideGround = true;
            playerVelocityY--;
            playerVelocityX -= signnum(playerVelocityX);

        }

        if (!collideGround){

            player.move( sf::Vector2f(0.f, gravity) );
            playerPosY -= gravity;

        }

        window.clear(sf::Color(0, 120, 250));
        window.draw(ground);
        window.draw(player);
        window.display();

    }

    return 0;

}
