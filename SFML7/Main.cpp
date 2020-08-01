#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"

static const float VIEW_HIEGHT = 512.0f;

void ResizeView(sf::RenderWindow& window, sf::View& view) {
    float aspectRatio = (float)window.getSize().x / (float)window.getSize().y;
    view.setSize(VIEW_HIEGHT * aspectRatio, VIEW_HIEGHT);
}

using namespace std;
int main(){
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial!", sf::Style::Close | sf::Style::Resize);
    
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HIEGHT, VIEW_HIEGHT));

    sf::Texture playerTexture;
    playerTexture.loadFromFile("tux_from_linux_all.png");
    
    Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f,200.0f);

    std::vector<Platform> platforms;

    platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));

    float deltaTime = 0.0f;
    sf::Clock clock;

    /*Not Needed cuz of including Animation header file. This Section of code allows us to print any sprite from uploaded image, but in static mode*/
    //sf::Vector2u textureSize = playerTexture.getSize();
    //textureSize.x /= 3;
    //textureSize.y /= 9;
    //player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y));

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f / 20.0f)
            deltaTime = 1.0f / 20.0f;

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                ResizeView(window, view);
                break;
            }
        }
        player.Update(deltaTime);

        sf::Vector2f direction;

        /*For nth platforms*/
        //for (int i = 0; i < platforms.size(); i++)
        //{
        //    Platform& platform = platforms[i];
        //}

        Collider playerCollision = player.GetCollider();

        for (Platform& platform : platforms)
        {
            if (platform.GetCollider().CheckCollision(playerCollision,direction,1.0f))
            {
                player.OnCollision(direction);
            }
        }

        view.setCenter(player.GetPosition());

        window.clear(sf::Color(150,150,150));
        window.setView(view);
        player.Draw(window);
        
        for (Platform& platform : platforms)
        platform.Draw(window);
        
        window.display();
    }
    return 0;
}