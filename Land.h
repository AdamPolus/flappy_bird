#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Land:public sf::Sprite{
public:
    Land(std::string filename,float size){

       if(texture_.loadFromFile(filename))
            setTexture(texture_);
        sf::Sprite sprite,sprite2;
        sprite.setPosition(0.0,size-sprite.getGlobalBounds().height);
        sprite2.setPosition(sprite.getGlobalBounds().width,size-sprite.getGlobalBounds().height);

        land_spirites.emplace_back(sprite);
        land_spirites.emplace_back(sprite2);
    }
    void Move_land(float dt);
    void Draw_land();

private:
    std::vector<sf::Sprite>land_spirites;
    sf::Texture texture_;
};
