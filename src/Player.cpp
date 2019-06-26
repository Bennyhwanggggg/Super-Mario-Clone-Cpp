#include "Player.h"
#include "Core.h"
#include "stdlib.h"
#include "time.h"

Player::Player(SDL_Renderer* rR, float fXPos, float fYPos) {
    this->fXPos = fXPos;
    this->fYPos = fYPos;

    this->iNumOfLives = 3;
    this->iSpriteID = 1;
    this->iScore = this->iCoins = 0;
    this->iFrameID = 0;
    this->iComboPoints = 1;

    this->nextBubbleTime = 0;
    this->nextFallFrameID = 0;

    this->powerLVL = 0;
    this->inLevelAnimation = false;
    this->inLevelAnimationType = false;

    this->unKillAble = false;
    this->startEffect = false;
    this->unKillAbleTimeFrameID = 0;

    this->inLevelDownAnimation = false;
    this->inLevelDownAnimationFrameID = 0;

    this->moveDirection = true;
    this->currentMaxMove = 4;
    this->moveSpeed = 0;
    this->bMove = false;
    this->changeMoveDirection = false;
    this->bSquat = false;

    this->onPlatformID = -1;
    this->springJump = false;

    this->iTimePassed = SDL_GetTicks();

    this->jumpState = 0;
    this->startJumpSpeed = 7.6f;
    this->currentFallingSpeed = 2.7f;

    this->iMoveAnimationTime = 0;
    this->nextFireBallFrameID = 8;
    
}