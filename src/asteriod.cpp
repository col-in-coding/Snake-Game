#include "asteriod.h"
#include "game_object.h"

#include "SDL.h"
#include <iostream>

Asteriod::Asteriod()
{
    std::cout << "Asteriod Constructor" << "\n";
}

Asteriod::Asteriod(int grid_w, int grid_h) : GameObject(grid_w, grid_h)
{
    SetColor(std::make_unique<Color>(0xFF, 0x00, 0x00, 0xFF));
    ResetBodyCell();
    _vx = 0.05f;
    _vy = 0.05f;
}

Asteriod::~Asteriod(){
    std::cout << "Asteriod Destructor" << "\n";
}

void Asteriod::Move()
{
    _nextx += _vx;
    _nexty += _vy;
    
    SDL_Point next_cell{
        static_cast<int>(_nextx),
        static_cast<int>(_nexty)
    };
    body[0] = next_cell;
}

// bool Asteriod::IsAsteriodCell(int x, int y)
// {
//     return false;
// }

void Asteriod::ResetBodyCell()
{
    _nextx = 0;
    _nexty = 3;

    SDL_Point bodyCell{
        static_cast<int>(_nextx),
        static_cast<int>(_nexty)};
    body.emplace_back(bodyCell);
}