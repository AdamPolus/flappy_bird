#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#define ROTATION_SPEED 100.0f
#define GRAVITY 350.0f
#define FLYING_SPEED 950.0f

class Bird : public sf::Sprite
{
public:
    Bird(int fps,std::string filename){
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
                rotation_ =0;
                  if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    setTextureRect(frames_[which_frame_]);
                    if(which_frame_ >= 2){
                        which_frame_ = 0;
                    }
                    else
                        which_frame_++;
                    }
                  else{
                    setTextureRect(frames_[which_frame_]);
                    if(which_frame_ == frames_.size()-1 || which_frame_ <= 2){
                    which_frame_ = 3;
                    }
                    else
                     which_frame_++;
                    }
            }




            for(auto &s : shapes_vec){
            if(getGlobalBounds().intersects(s->getGlobalBounds())){
               move(0,-std::abs(vertical_speed_*elapsed.asSeconds()));
               vertical_speed_ = 0;
               jump_ = false;
               }

            }

        }

    void update (float dt){



        move(350.0*dt,0.0);


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                         if(!jump_){
                             jump_ = true;

                         }
                  }



        //falling
//        move(0.0,GRAVITY *dt);

    }
private:
    bool jump_;
    float move_horizontal_speed_ = 200;
    float move_vertical_speed_ = 200;
    float jump_speed_ = 200;
    float acceleration_ = 20;
    float vertical_speed_ = 0;
    float horizontal_speed_ = 350.f;
    float timespend_;
    int fps_=0;
    unsigned which_frame_=0;
    sf::Texture texture_;
    std::vector<sf::IntRect> frames_;
    float rotation_;
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

