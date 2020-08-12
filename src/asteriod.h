#ifndef ASTERIOD_H
#define ASTERIOD_H

#include "SDL.h"
#include "game_object.h"

class Asteriod : public GameObject {
    public:
        Asteriod(int grid_w, int grid_h);

        void Update();
    private:
        SDL_Point NewAsteriod();

};

#endif


