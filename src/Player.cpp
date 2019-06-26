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


    // ----- LOAD SPRITE
	std::vector<std::string> tempS;
	std::vector<unsigned int> tempI;

	srand((unsigned)time(NULL));

	// ----- 0
	tempS.push_back("mario/mario_death");
	tempI.push_back(0);
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();

	// ----- 1
	tempS.push_back("mario/mario");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 2
	tempS.push_back("mario/mario_move0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 3
	tempS.push_back("mario/mario_move1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 4
	tempS.push_back("mario/mario_move2");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 5
	tempS.push_back("mario/mario_jump");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 6
	tempS.push_back("mario/mario_st");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 7
	tempS.push_back("mario/mario"); // SQUAT
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 8
	tempS.push_back("mario/mario_underwater0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 9
	tempS.push_back("mario/mario_underwater1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 10
	tempS.push_back("mario/mario_end");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 11
	tempS.push_back("mario/mario_end1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();

	// ---------- BIG
	// ----- 12
	tempS.push_back("mario/mario1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 13
	tempS.push_back("mario/mario1_move0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 14
	tempS.push_back("mario/mario1_move1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 15
	tempS.push_back("mario/mario1_move2");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 16
	tempS.push_back("mario/mario1_jump");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 17
	tempS.push_back("mario/mario1_st");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 18
	tempS.push_back("mario/mario1_squat"); // SQUAT
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 19
	tempS.push_back("mario/mario1_underwater0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 20
	tempS.push_back("mario/mario1_underwater1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 21
	tempS.push_back("mario/mario1_end");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 22
	tempS.push_back("mario/mario1_end1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();

	// ----- 23
	tempS.push_back("mario/mario2");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 24
	tempS.push_back("mario/mario2_move0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 25
	tempS.push_back("mario/mario2_move1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 26
	tempS.push_back("mario/mario2_move2");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 27
	tempS.push_back("mario/mario2_jump");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 28
	tempS.push_back("mario/mario2_st");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 29
	tempS.push_back("mario/mario2_squat"); // SQUAT
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 30
	tempS.push_back("mario/mario2_underwater0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 31
	tempS.push_back("mario/mario2_underwater1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 32
	tempS.push_back("mario/mario2_end");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 33
	tempS.push_back("mario/mario2_end1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();

	// ----- 34
	tempS.push_back("mario/mario2s");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 35
	tempS.push_back("mario/mario2s_move0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 36
	tempS.push_back("mario/mario2s_move1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 37
	tempS.push_back("mario/mario2s_move2");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 38
	tempS.push_back("mario/mario2s_jump");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 39
	tempS.push_back("mario/mario2s_st");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 40
	tempS.push_back("mario/mario2s_squat"); // SQUAT
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 41
	tempS.push_back("mario/mario2s_underwater0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 42
	tempS.push_back("mario/mario2s_underwater1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 43
	tempS.push_back("mario/mario2s_end");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 44
	tempS.push_back("mario/mario2s_end1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();

	// ----- 45
	tempS.push_back("mario/mario_s0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 46
	tempS.push_back("mario/mario_s0_move0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 47
	tempS.push_back("mario/mario_s0_move1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 48
	tempS.push_back("mario/mario_s0_move2");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 49
	tempS.push_back("mario/mario_s0_jump");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 50
	tempS.push_back("mario/mario_s0_st");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 51
	tempS.push_back("mario/mario_s0"); // SQUAT
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 52
	tempS.push_back("mario/mario_s0_underwater0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 53
	tempS.push_back("mario/mario_s0_underwater1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 54
	tempS.push_back("mario/mario_s0_end");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 55
	tempS.push_back("mario/mario_s0_end1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();

	// ----- 56
	tempS.push_back("mario/mario_s1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 57
	tempS.push_back("mario/mario_s1_move0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 58
	tempS.push_back("mario/mario_s1_move1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 59
	tempS.push_back("mario/mario_s1_move2");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 60
	tempS.push_back("mario/mario_s1_jump");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 61
	tempS.push_back("mario/mario_s1_st");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 62
	tempS.push_back("mario/mario_s1"); // SQUAT
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 63
	tempS.push_back("mario/mario_s1_underwater0");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 64
	tempS.push_back("mario/mario_s1_underwater1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 65
	tempS.push_back("mario/mario_s1_end");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 66
	tempS.push_back("mario/mario_s1_end1");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();

	// ----- LOAD SPRITE

	// ----- 67
	tempS.push_back("mario/mario_lvlup");
	sMario.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
}

Player::~Player(void) {
	for(std::vector<Sprite*>::iterator i = sMario.begin(); i != sMario.end(); i++) {
		delete (*i);
	}

	delete tMarioLVLUP;
}

void Player::Update() {
	playerPhysics();
	movePlayer();

	if(iFrameID > 0) {
		--iFrameID;
	} else if(iComboPoints > 1) {
		--iComboPoints;
	}

	if(powerLVL == 2) {
		if(nextFireBallFrameID > 0) {
			--nextFireBallFrameID;
		}
	}

	if(inLevelDownAnimation) {
		if(inLevelDownAnimationFrameID > 0) {
			--inLevelDownAnimationFrameID;
		} else {
			unKillAble = false;
		}
	}
}

void Player::playerPhysics() {
	if(!CCore::getMap()->getUnderWater()) {
		if (jumpState == 1) {
			updateYPos(-(int)currentJumpSpeed);
			currentJumpDistance += (int)currentJumpSpeed;

			currentJumpSpeed *= (currentJumpDistance / jumpDistance > 0.75f ? 0.972f : 0.986f);
		
			if (currentJumpSpeed < 2.5f) {
				currentJumpSpeed = 2.5f;
			}

			if(!CCFG::keySpace && currentJumpDistance > 64 && !springJump) {
				jumpDistance = 16;
				currentJumpDistance = 0;
				currentJumpSpeed = 2.5f;
			}

			if (jumpDistance <= currentJumpDistance) {
				jumpState = 2;
			}
		} else {
			if(onPlatformID == -1) {
				onPlatformID = CCore::getMap()->checkCollisionWithPlatform((int)fXPos, (int)fYPos, getHitBoxX(), getHitBoxY());
				if(onPlatformID >= 0) {
					if (CCore::getMap()->checkCollisionLB((int)(fXPos - CCore::getMap()->getXPos() + 2), (int)fYPos + 2, getHitBoxY(), true) || CCore::getMap()->checkCollisionRB((int)(fXPos - CCore::getMap()->getXPos() - 2), (int)fYPos + 2, getHitBoxX(), getHitBoxY(), true)) {
						onPlatformID = -1;
						resetJump();
					} else {
						fYPos = (float)CCore::getMap()->getPlatform(onPlatformID)->getYPos() - getHitBoxY();
						resetJump();
						CCore::getMap()->getPlatform(onPlatformID)->turnON();
					}
				}
			} else {
				onPlatformID = CCore::getMap()->checkCollisionWithPlatform((int)fXPos, (int)fYPos, getHitBoxX(), getHitBoxY());
			}
		
			if(onPlatformID >= 0) {
				if (CCore::getMap()->checkCollisionLB((int)(fXPos - CCore::getMap()->getXPos() + 2), (int)fYPos + 2, getHitBoxY(), true) || CCore::getMap()->checkCollisionRB((int)(fXPos - CCore::getMap()->getXPos() - 2), (int)fYPos + 2, getHitBoxX(), getHitBoxY(), true)) {
					onPlatformID = -1;
					resetJump();
				} else {
					fYPos += CCore::getMap()->getPlatform(onPlatformID)->getMoveY();
					CCore::getMap()->getPlatform(onPlatformID)->moveY();
					//if(moveSpeed == 0)
					CCore::getMap()->setXPos(CCore::getMap()->getXPos() - CCore::getMap()->getPlatform(onPlatformID)->getMoveX());
			
					jumpState = 0;
				}
			}
			else if (!CCore::getMap()->checkCollisionLB((int)(fXPos - CCore::getMap()->getXPos() + 2), (int)fYPos + 2, getHitBoxY(), true) &&
				!CCore::getMap()->checkCollisionRB((int)(fXPos - CCore::getMap()->getXPos() - 2), (int)fYPos + 2, getHitBoxX(), getHitBoxY(), true)) {

				if(nextFallFrameID > 0) {
					--nextFallFrameID;
				} else {
					currentFallingSpeed *= 1.05f;

					if (currentFallingSpeed > startJumpSpeed) {
						currentFallingSpeed = startJumpSpeed;
					}

					updateYPos((int)currentFallingSpeed);
				}
				

				jumpState = 2;

				setMarioSpriteID(5);
			} else if(jumpState == 2) {
				resetJump();
			} else {
				checkCollisionBot(0, 0);
			}
		}
	} else {
		if(nextBubbleTime + 685 < SDL_GetTicks()) {
			CCore::getMap()->addBubble((int)(fXPos - CCore::getMap()->getXPos() + (moveDirection ? getHitBoxX() - rand()%8 : rand()%8)), (int)fYPos + 4);
			nextBubbleTime = SDL_GetTicks() + rand()%715;
		}

		if (jumpState == 1) {
			if(fYPos > CCFG::GAME_HEIGHT - 12*32 - 16) {
				updateYPos(-2);
				currentJumpDistance += 2;

				swimingAnimation();

				if (jumpDistance <= currentJumpDistance) {
					jumpState = 2;
					currentJumpDistance = 0;
					nextFallFrameID = 4;
				}
			} else {
				jumpState = 2;
				nextFallFrameID = 14;
				currentJumpDistance = 0;
			}
		} else {
			if (!CCore::getMap()->checkCollisionLB((int)(fXPos - CCore::getMap()->getXPos() + 2), (int)fYPos + 2, getHitBoxY(), true) &&
				!CCore::getMap()->checkCollisionRB((int)(fXPos - CCore::getMap()->getXPos() - 2), (int)fYPos + 2, getHitBoxX(), getHitBoxY(), true)) {

				if(nextFallFrameID > 0) {
					--nextFallFrameID;
				} else {
					if(currentJumpDistance < 32) {
						updateYPos(1);
						++currentJumpDistance;
					} else {
						updateYPos(2);
					}
				}

				jumpState = 2;

				swimingAnimation();
			} else if(jumpState == 2) {
				resetJump();
			}
		}
	}
}

void Player::movePlayer() {
    if (bMove && !changeMoveDirection && (!bSquat || powerLVL == 0)) {
        if (moveSpeed > currentMaxMove) {
            --moveSpeed;
        } else if (SDL_GetTicks() - (100 + 35*moveSpeed) >= iTimePassed && moveSpeed < currentMaxMove) {
            ++moveSpeed;
            iTimePassed = SDL_GetTicks();
        } else if (moveSpeed == 0) {
            moveSpeed = 1;
        }
    } else {
        if (SDL_GetTicks() - (50 + 15 * (currentMaxMove - moveSpeed) * (bSquat && powerLVL > 0 ? 6 : 1)) > iTimePassed && moveSpeed != 0) {
            --moveSpeed;
            iTimePassed = SDL_GetTicks();
            if (jumpState == 0 && !CCore::getMap()->getUnderWater()) {
                setMarioSpriteID(6);
            }
        }

        if (changeMoveDirection && moveSpeed <= 1) {
            moveDirection = newMoveDirection;
            changeMoveDirection = false;
            bMove = true;
        }
    }

    if (moveSpeed > 0) {
        if (moveDirection) {
            updateXPos(moveSpeed);
        } else {
            updateXPos(-moveSpeed);
        }

        // Moving Animation
        if (CCore::getMap()->getUnderWater()) {
            swimingAnimation();
        } else if (!changeMoveDirection && jumpState == 0 && bMove) {
            moveAnimation();
        }
    } else if (jumpState == 0) {
        setMarioSpriteID(1);
        updateXPos(0);
    } else {
        updateXPos(0);
    }

    if (bSquat && !CCore::getMap()->getUnderWater() && powerLVL > 0) {
        setMarioSpriteID(7);
    }
}

void Player::powerUPAnimation() {
    if (inLevelAnimation) {
        if (inLevelAnimation%15 < 5) {
            iSpriteID = 12;
            if (inLevelAnimationFrameID != 0 && inLevelAnimationFrameID%15 == 0) {
                fYPos += 16;
                fXPos -= 4;
            }
        } else if (inLevelAnimation%15 < 10) {
            iSpriteID = 67;
            if (inLevelAnimationFrameID%15 == 5) {
                fYPos += 16;
                fXPos += 1;
            }
        } else {
            iSpriteID = 1;
			if(inLevelAnimationFrameID%15 == 10) {
				fYPos -= 32;
				fXPos += 3;
			}
        }

        ++inLevelAnimationFrameID;
		if(inLevelAnimationFrameID > 59) {
			inLevelAnimation = false;
			fYPos += 32;
			if(jumpState != 0) {
				setMarioSpriteID(5);
			}
		}

    } else if (powerLVL == 1) {
        if(inLevelAnimationFrameID%15 < 5) {
			iSpriteID = 1;
			if(inLevelAnimationFrameID != 0 && inLevelAnimationFrameID%15 == 0) {
				fYPos += 32;
				fXPos += 4;
			}
		} else if(inLevelAnimationFrameID%15 < 10) {
			iSpriteID = 67;
			if(inLevelAnimationFrameID%15 == 5) {
				fYPos -= 16;
				fXPos -= 3;
			}
		} else {
			iSpriteID = 12;
			if(inLevelAnimationFrameID%15 == 10) {
				fYPos -= 16;
				fXPos -= 1;
			}
		}

        ++inLevelAnimationFrameID;
		if(inLevelAnimationFrameID > 59) {
			inLevelAnimation = false;
			if(jumpState != 0) {
				setMarioSpriteID(5);
			}
		}

    } else if (powerLVL == 2) {
        if (inLevelAnimationFrameID%10 < 5) {
            iSpriteID = iSpriteID%11 + 22;
        } else {
            iSpriteID = iSpriteID%11 + 33;
        }

        ++inLevelAnimationFrameID;
        if (inLevelAnimationFrameID > 59) {
            inLevelAnimation = false;
            if (jumpState != 0) {
                setMarioSpriteID(5);
            }
            iSpriteID = iSpriteID%11 + 22;
        }
    } else {
        inLevelAnimation = false;
    }
}