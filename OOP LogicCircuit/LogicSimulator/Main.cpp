#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    sf::Texture texture;
    if (!texture.loadFromFile("../assets/AND.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Logic Simulator");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(sprite);

        // end the current frame
        window.display();
    }
    return 0;
}