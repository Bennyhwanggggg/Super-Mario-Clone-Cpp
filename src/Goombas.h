#pragma once

#ifndef GOOMBAS_H
#define GOOMBAS_H

#include "Minion.h"

class Goombas: public Minion
{
private:

public:
    Goombas(int iX, int iY, int iBlockID, bool moveDirection);
    ~Goombas(void);

    void Update();
    void Draw(SDL_Renderer* rR, CIMG* iIMG);
    void collisionWithPlayer(bool TOP);
    void setMinionState(int minionState);
};

#endif // ! GOOMBAS_H