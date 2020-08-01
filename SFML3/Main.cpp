#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

using namespace std;
int main(){
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial!",sf::Style::Close| sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.0f,150.0f));
    
    player.setPosition(206.0f, 206.0f);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("tux_from_linux_all.png");
    player.setTexture(&playerTexture);
    
    Animation animation(&playerTexture, sf::Vector2u(3, 9), 0.3f);

    float deltaTime = 0.0f;
    sf::Clock clock;

    /*Not Needed cuz of including Animation header file. This Section of code allows us to print any sprite from uploaded image, but in static mode*/
    //sf::Vector2u textureSize = playerTexture.getSize();
    //textureSize.x /= 3;
    //textureSize.y /= 9;
    //player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y));

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        animation.Update(0, deltaTime);
        player.setTextureRect(animation.uvRect);

        window.clear(sf::Color(150,150,150));
        window.draw(player);
        window.display();
    }
    return 0;
}