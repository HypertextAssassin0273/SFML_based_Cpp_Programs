#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main(){
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial!",sf::Style::Close| sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.0f,100.0f));
    player.setFillColor(sf::Color::Red);
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            switch (event.type){
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                cout <<"New Window Width: "<< event.size.width << ", New Window Height: " << event.size.height << endl;
                break;
            case sf::Event::TextEntered:
                if (event.text.unicode < 128)
                    cout << (char)event.text.unicode;
                    //printf("%c", event.text.unicode);
                break;
            }
        }
        /*Keyboard Input*/
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            player.move(-0.1f,0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            player.move(0.1f, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            player.move(0.0f, -0.1f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            player.move(0.0f, 0.1f);

        window.clear();
        window.draw(player);
        window.display();
    }
    return 0;
}
