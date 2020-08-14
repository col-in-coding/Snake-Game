#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory>
#include <iostream>
#include <thread>
#include <deque>
#include <future>
#include <mutex>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "asteriod.h"

template <class Food>
class Foodstore
{
private:
    std::mutex _mutex;
    std::condition_variable _cond;
    std::deque<Food> _shelf;

public:
    Foodstore() {};

    bool HasFood() {return _shelf.size() > 0;}

    // Perchures food from foodstore
    Food perchures() {
        // perform vector modification under the lock
        std::unique_lock<std::mutex> uLock(_mutex);
        // temporarily unlocked inside wait
        _cond.wait(uLock, [this] { return !_shelf.empty(); }); 

        Food food = std::move(_shelf.front());
        _shelf.pop_front();

        return food;
    }

    // Foodstore reload food
    void reload(Food food) {
        // perform vector modification under the lock
        std::lock_guard<std::mutex> uLock(_mutex);

        // add vector to queue
        std::cout << "   New Food (" << food.x << ", " << food.y << ") will be added to the shelf" << '\n';
        _shelf.push_back(std::move(food));
        _cond.notify_one();
    }
};

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
    std::shared_ptr<Foodstore<SDL_Point>> _foodstore;
    Asteriod *_asteriod;
    SDL_Point _food;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

    int score{0};

    SDL_Point NewFood();
    void PlaceFood();
    void Update();
};

#endif