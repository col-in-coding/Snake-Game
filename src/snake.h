#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include "game_object.h"

class Snake : public GameObject {
 public:
  Snake(int grid_w, int grid_h)
      : head_x(grid_w / 2),
        head_y(grid_h / 2)
      {
          grid_width = grid_w;
          grid_height = grid_h;
      }

  void Move();

  void GrowBody();
  bool SnakeCell(int x, int y);

  int size{1};
  bool alive{true};
  float head_x;
  float head_y;

 private:
  void MoveHead();
  void Move(SDL_Point &current_cell, SDL_Point &prev_cell);
};

#endif