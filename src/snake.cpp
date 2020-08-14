#include "snake.h"
#include "game_object.h"
#include <cmath>
#include <iostream>

Snake::Snake(int grid_w, int grid_h) : GameObject(grid_w, grid_h)
{
    head_x = grid_w / 2;
    head_y = grid_h / 2;

    SetColor();
    _speed = 0.1f;
}

void Snake::Move()
{
    SDL_Point prev_cell{
        static_cast<int>(head_x),
        static_cast<int>(
            head_y)}; // We first capture the head's cell before updating.
    MoveHead();
    SDL_Point current_cell{
        static_cast<int>(head_x),
        static_cast<int>(head_y)}; // Capture the head's cell after updating.

    // Update all of the body vector items if the snake head has moved to a new
    // cell.
    if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y)
    {
        Move(current_cell, prev_cell);
    }
}

void Snake::MoveHead()
{
    switch (direction)
    {
    case Direction::kUp:
        head_y -= _speed;
        break;

    case Direction::kDown:
        head_y += _speed;
        break;

    case Direction::kLeft:
        head_x -= _speed;
        break;

    case Direction::kRight:
        head_x += _speed;
        break;
    }

    // Wrap the Snake around to the beginning if going off of the screen.
    head_x = fmod(head_x + grid_width, grid_width);
    head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::Move(SDL_Point &current_head_cell, SDL_Point &prev_head_cell)
{
    // Add previous head location to vector
    body.push_back(prev_head_cell);

    if (!growing)
    {
        // Remove the tail from the vector.
        body.erase(body.begin());
    }
    else
    {
        growing = false;
        size++;
    }

    // Check if the snake has died.
    for (auto const &item : body)
    {
        if (current_head_cell.x == item.x && current_head_cell.y == item.y)
        {
            alive = false;
            UpdateHeadColor(new Color(0xFF, 0x00, 0x00, 0xFF));
        }
        if (_asteriod->IsAsteriodCell(item.x, item.y))
        {
            alive = false;
            UpdateBodyColor(new Color(0xFF, 0x00, 0x00, 0xFF));
        }
    }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y)
{
    if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y))
    {
        return true;
    }
    for (auto const &item : body)
    {
        if (x == item.x && y == item.y)
        {
            return true;
        }
    }
    return false;
}

void Snake::SetColor()
{
    _headColor = std::make_unique<Color>(0x00, 0x7A, 0xCC, 0xFF);
    _bodyColor = std::make_unique<Color>(0xFF, 0xFF, 0xFF, 0xFF);
}

void Snake::UpdateHeadColor(Color *color)
{
    _headColor.reset(color);
}

void Snake::UpdateBodyColor(Color *color)
{
    _bodyColor.reset(color);
}

void Snake::SetAsteriod(Asteriod *asteriod)
{
    _asteriod = asteriod;
}