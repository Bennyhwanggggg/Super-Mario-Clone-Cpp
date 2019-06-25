#include "Minion.h"
#include "Core.h"

Minion::Minion(void) {
    this->minionState = 0;
    this->iHitBoxX = this->iHitBoxY = 32;

    this->killOtherUnits = false;
    this->minionSpawned = false;
    this->collisionOnlyWithPlayer = false;

    this->moveDirection = true;
    this->moveSpeed = 1;

    this->jumpState = 0;
    this->startJumpSpeed = 6.6f;
    this->currentFallingSpeed = 2.2f;
    this->currentJumpSpeed = 0;
    this->jumpDistance = 0;
    this->currentJumpDistance = 0;

    this->deadTime = -1;
    this->onAnotherMinion = false;
}

Minion::~Minion(void) {

}

void Minion::Update() {

}

void Minion::Draw(SDL_Renderer* rR, CIMG* iIMG) {

}

bool Minion::updateMinion() {
    if (!minionSpawned) {
        Spawn();
    } else {
        minionPhysics();
    }
    return minionSpawned;
}

void Minion::minionPhysics() {
    if (jumpState == 1) {
        physicsState1();
    } else {
        if (!CCore::getMap()->checkCollisionLB((int)fXPos + 2, (int)fYPos + 2, iHitBoxY, true) && !CCore::getMap()->checkCollsionRB((int)fXPos - 2, (int)fYPos + 2, iHitBoxX, iHitBoxY, true) && !onAnotherMinion) {
            physicsState2();
        } else {
            jumpState = 0;
            onAnotherMinion = false;
        }
    }
}

// Physics for jump
void Minion::physicsState1() {
    updateYPos(-(int)currentJumpSpeed);
    currentJumpDistance += (int)currentJumpSpeed;
    currentJumpSpeed *= (currentJumpDistance / jumpDistance > 0.75f ? 0.97f : 0.99f);

    if (currentJumpSpeed < 2.5f) {
        currentJumpSpeed = 2.5f;
    }
    if (jumpDistance <= currentJumpDistance) {
        jumpState = 2;
    }
}

// Physics for falling
void Minion::physicsState2() {
	currentFallingSpeed *= 1.06f;

	if (currentFallingSpeed > startJumpSpeed) {
		currentFallingSpeed = startJumpSpeed;
	}

	updateYPos((int)currentFallingSpeed);
	jumpState = 2;

	if (fYPos >= CCFG::GAME_HEIGHT) {
		minionState = -1;
	}
}

void Minion::updateXPos() {
    // Left
    if (moveDirection) {
        if (CCore::getMap()->checkCollisionLB((int)fXPos - moveSpeed, (int)fYPos - 2, iHitBoxY, true) || CCore::getMap()->checkCollisionLT((int)fXPos - moveSpeed, (int)fYPos + 2, true)) {
            moveDirection = !moveDirection;
            if (killOtherUnits && fXPos > -CCore::getMap()->getXPos() - 64 && fXPos < -CCore::getMap()->getXPos() + CCFG::GAME_WIDTH + 64 + iHitBoxX) {
                CCFG::getMusic()->PlayChunk(CCFG::getMusic()->cBLOCKHIT);
            }
        } else {
            fXPos -= jumpState == 0 ? moveSpeed : (moveSpeed/2.0f);
        }
    } else {
        if (CCore::getMap()->checkCollisionRB((int)fXPos + moveSpeed, (int)fYPos - 2, iHitBoxX, iHitBoxY, true) || CCore::getMap()->checkCollisionRT((int)fXPos + moveSpeed, (int)fYPos + 2, iHitBoxX, true)) {
			moveDirection = !moveDirection;
			if(killOtherUnits && fXPos > -CCore::getMap()->getXPos() - 64 && fXPos < -CCore::getMap()->getXPos() + CCFG::GAME_WIDTH + 64 + iHitBoxX) {
                CCFG::getMusic()->PlayChunk(CCFG::getMusic()->cBLOCKHIT);
            }
		} else {
			fXPos += (jumpState == 0 ? moveSpeed : moveSpeed/2.0f);
		}
    }
    if(fXPos < -iHitBoxX) {
		minionState = -1;
	}
}

void Minion::updateYPos(int iN) {
	if (iN > 0) {
		if (!CCore::getMap()->checkCollisionLB((int)fXPos + 2, (int)fYPos + iN, iHitBoxY, true) && !CCore::getMap()->checkCollisionRB((int)fXPos - 2, (int)fYPos + iN, iHitBoxX, iHitBoxY, true)) {
			fYPos += iN;
		} else {
			if (jumpState == 1) {
				jumpState = 2;
			}
			updateYPos(iN - 1);
		}
	}
	else if (iN < 0) {
		if (!CCore::getMap()->checkCollisionLT((int)fXPos + 2, (int)fYPos + iN, true) && !CCore::getMap()->checkCollisionRT((int)fXPos - 2, (int)fYPos + iN, iHitBoxX, true)) {
			fYPos += iN;
		} else {
			if (jumpState == 1) {
				jumpState = 2;
			}
			updateYPos(iN + 1);
		}
	}

	if((int)fYPos % 2 == 1) {
		fYPos += 1;
	}
}