#include "bird.h"
#include "Land.h"

int main() {

    std::vector<std::unique_ptr<sf::Sprite>> shapes;
        sf::Texture texture_grass;
            if(!texture_grass.loadFromFile("sea.png")) { return 1; }


            create_shapes(shapes,texture_grass);

    // create the window
    sf::RenderWindow window(sf::VideoMode(1200, 800), "My window");
    window.setFramerateLimit(120);

    sf::Clock clock;

    Land background("land",window.getSize().y);


    sf::Vector2f position_bird(window.getSize().x/2, window.getSize().y/2);
    Bird Flappy(10,"character.png");
    Flappy.setPosition(window.getSize().x/2,window.getSize().y/2);
    Flappy.add_animation_frame(sf::IntRect(0, 0, 50, 37)); // hero standing frame 1
    Flappy.add_animation_frame(sf::IntRect(50, 0, 50, 37)); // hero standing frame 2
    Flappy.add_animation_frame(sf::IntRect(100, 0, 50, 37)); // hero standing frame 3
    Flappy.add_animation_frame(sf::IntRect(150, 0, 50, 37)); // hero running frame 1
    Flappy.add_animation_frame(sf::IntRect(200, 0, 50, 37)); // hero running frame 1
    Flappy.add_animation_frame(sf::IntRect(250, 0, 50, 37)); // hero running frame 1
    Flappy.add_animation_frame(sf::IntRect(300, 0, 50, 37)); // hero running frame 1
    Flappy.add_animation_frame(sf::IntRect(350, 0, 50, 37)); // hero running frame 1
    Flappy.add_animation_frame(sf::IntRect(400, 0, 50, 37)); // hero running frame 1


    // run the program as long as the window is open
    while (window.isOpen()) {

        //clock restart
        sf::Time elapsed = clock.restart();
        float rot = clock.getElapsedTime().asSeconds() * 90;

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Flappy.animate(elapsed,shapes);

        Flappy.update(rot*45);
        // clear the window with black color
        window.clear(sf::Color::Black);



        // draw everything here...
        window.draw(Flappy);

        for(auto &s : shapes){
                           window.draw(*s);
        }



        // end the current frame
        window.display();
    }

    return 0;
}
