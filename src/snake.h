#ifndef SNAKE_H
#define SNAKE_H

#include "SDL.h"
#include "game_object.h"
#include "asteriod.h"

class Snake : public GameObject
{
public:
    Snake(int grid_w, int grid_h);

    // getter and setter
    void SetAsteriod(Asteriod *asteriod);
    Color *GetBodyColor(){return _bodyColor.get();}
    Color *GetHeadColor(){return _headColor.get();}
    void UpdateHeadColor(Color *color);
    void UpdateBodyColor(Color *color);

    // Move the Snake. (override virtual function)
    void Move();

    void GrowBody();

    // Check if is Snake Cell
    bool SnakeCell(int x, int y);

    int size{1};
    bool alive{true};

    float head_x;
    float head_y;

private:
    // data handles (owned)
    std::unique_ptr<Color> _headColor;

    // data handles (not owned)
    Asteriod *_asteriod;

    void MoveHead();

    // Move Body
    void Move(SDL_Point &current_cell, SDL_Point &prev_cell);
    
    // overwrite the SetColor from GameObject
    void SetColor();
};

#endif