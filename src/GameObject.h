#ifndef GAME_OBJ_H
#define GAME_OBJ_H

#include <vector>
#include "SDL.h"

enum class Direction { kUp, kDown, kLeft, kRight };

class GameObject
{
public:
    Direction direction = Direction::kUp;
    std::vector<SDL_Point> body;
    float speed{0.1f};

protected:
    bool growing{false};
    int grid_width;
    int grid_height;
};


#endif