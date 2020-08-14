#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory>
#include <iostream>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "asteriod.h"

class Game
{
public:
    Game(std::size_t grid_width, std::size_t grid_height);
    ~Game();

    // getter and setter
    int GetScore() const;

    void Run(Controller const &controller, Renderer &renderer,
             std::size_t target_frame_duration);
    int GetSize() const;

    template <typename T>
    void print(const char *name, const T &v)
    {
        std::cout << name << ": " << v << '\n';
    }

private:
    // data handle (owned)
    std::unique_ptr<Snake> _snake;
    Asteriod *_asteriod;
    SDL_Point food;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

    int score{0};

    void PlaceFood();
    void Update();
};

#endif