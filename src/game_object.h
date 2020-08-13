#ifndef GAME_OBJ_H
#define GAME_OBJ_H

#include <iostream>
#include <vector>
#include <memory>
#include "SDL.h"

enum class Direction { kUp, kDown, kLeft, kRight };

struct Color
{
    Color(int r, int g, int b, int a)
        :r(r), g(g), b(b), a(a){}
    int r;
    int g;
    int b;
    int a;
};

class GameObject
{
public:
    GameObject(){
        std::cout << "Game Object Constructor" << '\n';
    }
    GameObject(int grid_width, int grid_height)
        :grid_width(grid_width), grid_height(grid_height){}
    Direction direction = Direction::kUp;
    std::vector<SDL_Point> body;
    
    // getter and setter
    void SetColor(std::unique_ptr<Color> color){_bodyColor = std::move(color);}
    float GetSpeed(){return _speed;}
    void SetSpeed(const float speed){_speed = speed;}
    void SpeedUp() {_speed += 0.02;}

    // Pure virtual function for the abstract class
    virtual void Move() = 0;

protected:
    bool growing{false};
    float _speed;
    int grid_width;
    int grid_height;
    std::unique_ptr<Color> _bodyColor;
};


#endif