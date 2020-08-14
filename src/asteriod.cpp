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
    std::cout << "Asteriod Overload Constructor" << "\n";

    SetColor(std::make_unique<Color>(0xFF, 0x00, 0x00, 0xFF));
    Reset();
}

Asteriod::~Asteriod(){
    std::cout << "Asteriod Destructor" << "\n";
}

void Asteriod::Move()
{
    _nextx += _vx;
    _nexty += _vy;
    
    if (_nextx > grid_width || _nexty > grid_height)
    {
        Reset();
    } else {
        SDL_Point next_cell{
            static_cast<int>(_nextx),
            static_cast<int>(_nexty)
        };
        body[0] = next_cell;
    }
}

// bool Asteriod::IsAsteriodCell(int x, int y)
// {
//     return false;
// }

void Asteriod::Reset()
{
    // reset the position
    _nextx = std::rand() % (grid_width - 10);
    _nexty = std::rand() % (grid_height - 10);
    if (_nextx > _nexty)
    {
        _nextx = 0;
    }

    // reset body cell
    body.clear();
    SDL_Point bodyCell{
        static_cast<int>(_nextx),
        static_cast<int>(_nexty)};
    body.emplace_back(bodyCell);

    // reset the speed
    _vx = 0.05f + (std::rand() % 3) * 0.02;
    _vy = 0.05f + (std::rand() % 3) * 0.02;
}