#include "asteriod.h"
#include "game_object.h"

#include "SDL.h"
#include <iostream>

Asteriod::Asteriod()
{
    std::cout << "Asteriod Constructor1" << "\n";
}

Asteriod::Asteriod(int grid_w, int grid_h) : GameObject(grid_w, grid_h)
{
    std::cout << "Asteriod Constructor2" << "\n";

    SetColor(std::make_unique<Color>(0xFF, 0x00, 0x00, 0xFF));
    Reset();
}

Asteriod::Asteriod(const Asteriod &source)
{
    std::cout << "Asteriod Copy Constructor" << '\n';
    grid_width = source.grid_width;
    grid_height = source.grid_height;
    _bodyColor = std::make_unique<Color>(source._bodyColor->r,
                                         source._bodyColor->g,
                                         source._bodyColor->b,
                                         source._bodyColor->a);
    Reset();
}

Asteriod::Asteriod(Asteriod &&source)
{
    std::cout << "Asteriod Move Constructor" << '\n';
    grid_width = source.grid_width;
    grid_height = source.grid_height;
    _bodyColor = std::move(source._bodyColor);
    Reset();
}

Asteriod& Asteriod::operator=(const Asteriod &source)
{
    std::cout << "Asteriod Assignment Operation" << '\n';
    grid_width = source.grid_width;
    grid_height = source.grid_height;
    _bodyColor = std::make_unique<Color>(source._bodyColor->r,
                                         source._bodyColor->g,
                                         source._bodyColor->b,
                                         source._bodyColor->a);
    Reset();
    return *this;
}

Asteriod& Asteriod::operator=(Asteriod &&source)
{
    std::cout << "Asteriod Move Assignment" << '\n';
    std::cout << "Asteriod Move Constructor" << '\n';
    grid_width = source.grid_width;
    grid_height = source.grid_height;
    _bodyColor = std::move(source._bodyColor);
    Reset();
    return *this;
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

bool Asteriod::IsAsteriodCell(const int &x, const int &y)
{
    return x == body[0].x && y == body[0].y;
}

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