#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main(){
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial!",sf::Style::Close| sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.0f,100.0f));
    player.setFillColor(sf::Color::Red);
    player.setOrigin(50.0f, 50.0f); //i.e setting origin at centre of object/sprite
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
        /*Mouse Input*/
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y)); //Note: 2nd type of casting is safe 
        }

        window.clear();
        window.draw(player);
        window.display();
    }
    return 0;
}
