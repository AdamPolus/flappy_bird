#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<string>
#include<vector>
#include<iostream>
class AnimatedSprite : public sf::Sprite {
public:
    AnimatedSprite(int fps,std::string filename){
        if(texture_.loadFromFile(filename))
            setTexture(texture_);
        fps_=fps;
    }
    void add_animation_frame(sf::IntRect rect){
        frames_.emplace_back(rect);
    }
    void animate(sf::Time &elapsed,std::vector<std::unique_ptr<sf::Sprite>> &shapes_vec){
        timespend_+=elapsed.asSeconds();
            if(timespend_>=(1.0/static_cast<float>(fps_))){
                timespend_=0;
                  if(horizontal_speed == 0){
                    setTextureRect(frames_[which_frame]);
                    if(which_frame >= 2){
                        which_frame = 0;
                    }
                    else
                        which_frame++;
                    }
                  else{
                    setTextureRect(frames_[which_frame]);
                    if(which_frame == frames_.size()-1 || which_frame <= 2){
                    which_frame = 3;
                    }
                    else
                     which_frame++;
                    }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                horizontal_speed = move_horizontal_speed;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                horizontal_speed = -move_horizontal_speed;
            }
            else{
                horizontal_speed = 0;
            }
            vertical_speed += acceleration*elapsed.asSeconds();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                             if(!jump_){
                                 jump_ = true;
                                 vertical_speed = -jump_speed_;
                             }
                      }
            move(horizontal_speed*elapsed.asSeconds(),vertical_speed*elapsed.asSeconds());

            for(auto &s : shapes_vec){
            if(getGlobalBounds().intersects(s->getGlobalBounds())){
               move(0,-std::abs(vertical_speed*elapsed.asSeconds()));
               vertical_speed = 0;
               jump_ = false;
               }

            }

        }
private:
    bool jump_;
    float move_horizontal_speed = 200;
    float jump_speed_ = 200;
    float acceleration = 200;
    float vertical_speed = 0;
    float horizontal_speed;
    float timespend_;
    int fps_=0;
    unsigned which_frame=0;
    sf::Texture texture_;
    std::vector<sf::IntRect> frames_;
};
void create_shapes(std::vector<std::unique_ptr<sf::Sprite>> &shapes_vec,sf::Texture &tex) {
    auto grass = std::make_unique<sf::Sprite>(tex);
    tex.setRepeated(true);
    grass->setPosition(0,560);
    //grass->setScale(1,0.3);
    grass->setTextureRect(sf::IntRect(0, 0, 800, 50));
    shapes_vec.push_back(std::move(grass));

    auto grass1 = std::make_unique<sf::Sprite>(tex);
    tex.setRepeated(true);
    grass1->setPosition(200,460);
    grass1->setScale(1,0.3);
    grass1->setTextureRect(sf::IntRect(0, 0, 50, 50));
    shapes_vec.push_back(std::move(grass1));

    auto grass2 = std::make_unique<sf::Sprite>(tex);
    tex.setRepeated(true);
    grass2->setPosition(250,360);
    grass2->setScale(1,0.3);
    grass2->setTextureRect(sf::IntRect(0, 0, 50, 50));
    shapes_vec.push_back(std::move(grass2));

    auto grass3 = std::make_unique<sf::Sprite>(tex);
    tex.setRepeated(true);
    grass3->setPosition(150,260);
    grass3->setScale(1,0.3);
    grass3->setTextureRect(sf::IntRect(0, 0, 50, 50));
    shapes_vec.push_back(std::move(grass3));

    auto grass4 = std::make_unique<sf::Sprite>(tex);
    tex.setRepeated(true);
    grass4->setPosition(400,160);
    grass4->setScale(1,0.3);
    grass4->setTextureRect(sf::IntRect(0, 0, 50, 50));
    shapes_vec.push_back(std::move(grass4));


}
