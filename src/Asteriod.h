#ifndef ASTERIOD_H
#define ASTERIOD_H

#include "SDL.h"

class asteriod
{
public:
    asteriod(int grid_width, int grid_height)
        : grid_width(grid_width),
          grid_height(grid_height),
          head_x(grid_width / 2),
          head_y(grid_height / 2);
    
    void Update();

private:
    /* data */
};


