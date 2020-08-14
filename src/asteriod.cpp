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
    SetBodyCell();
    _vx = 0.05f;
    _vy = 0.05f;
}

Asteriod::~Asteriod(){
    std::cout << "Asteriod Destructor" << "\n";
}

void Asteriod::Move()
{
    // int size = body.size()
    // for (SDL_Point &point : body)
    // {
    //     point.x += _vx;
    // }
}

// bool Asteriod::IsAsteriodCell(int x, int y)
// {
//     return false;
// }

void Asteriod::SetBodyCell()
{
    int body_x = 0;
    int body_y = 3;

    SDL_Point bodyCell{
        static_cast<int>(body_x),
        static_cast<int>(body_y)};
    body.emplace_back(bodyCell);
}