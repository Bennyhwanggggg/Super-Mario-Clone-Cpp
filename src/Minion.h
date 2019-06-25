#pragma once

#ifndef MINION_H
#define MINION_H

#include "header.h"
#include "CFG.h"
#include "IMG.h"

class Minion
{
public:
    Minion(void);
    ~Minion(void);

    int minionState;
    bool killOtherUnits;

    int iBlockID;
    float fXPos;
    float fYPos;

    int iHitBoxX;
    int iHitBoxY;

    bool minionSpawned;
    bool collisionOnlyWithPlayer;

    int deadTime;

    bool onAnotherMinion;

    // true = Left, false = Right
    bool moveDirection;
    int moveSpeed;
    int jumpState;

    float startJumpSpeed;
    float currentJumpSpeed;
    float jumpDistance;
    float currentJumpDistance;
    float currentFallingSpeed;

    virtual void Update();
    virtual void Draw(SDL_Renderer* rR, CIMG* iIMG);

    virtual void updateYPos(int iN);
    virtual void updateXPos();

    virtual bool updateMinion();
    virtual minionPhysics();

    virtual void collisionEffect();
    virtual void minionDeathAnimation();

    void physicsState1();
    void physicsState2();

    void Spawn();
    void startJump(int iH);
    void resetJump();

    virtual void collisionWithPlayer(bool TOP);
    virtual void points(int iPoints);
    virtual void collisionWithAnotherUnit();
    virtual void lockMinion();

    int getBlockID();
    void setBlockID(int iBlockID);
    int getMinionState();
    virtual void setMinionState(int minionState);
    virtual bool getPowerUP();
    int getXPos();
    int getYPos();
    void setYPos(int iYPos);
}

#endif // ! MINION_H