#include "Spring.h"
#include "Core.h"

Spring::Spring(int iXPos, int iYPos) {
    this->fXPos = (float)iXPos;
    this->fYPos = (float)iYPos + 2;

    this->iHitBoxX = 32;
    this->iHitBoxY = 72;

    this->iBlockID = CCore:getMap()->getLevelType() == 0 || CCore::getMap()->getLevelType() == 4 ? 37 : 40;

    this->minionState = 0;
    this->nextFrameID = 4;
    this->inAnimation = false;
}

Spring::~Spring(void) {

}

void Spring::Update() {
    if (inAnimation) {
        if (CCFG::keySpace) {
            extraJump = true;
            CCore::getMap()->getPlayer()->resetJump();
        }
    }
}