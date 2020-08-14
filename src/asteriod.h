#ifndef ASTERIOD_H
#define ASTERIOD_H

#include "SDL.h"
#include "game_object.h"

class Asteriod : public GameObject
{
    public:
        Asteriod();
        ~Asteriod();
        
        Asteriod(int grid_w, int grid_h);

        // getter and setter
        Color *GetBodyColor(){return _bodyColor.get();}

        // Move the Asteriod. (override virtual function)
        void Move();

        // Check if is Asteriod Cell
        // bool IsAsteriodCell(int x, int y);
    
    private:
        // Velocity of the asteriod
        float _vx;
        float _vy;
        float _nextx;
        float _nexty;
        void Reset();
};

#endif


