#include "header.h"
#include "Core.h"
#include "IMG.h"
#include "CFG.h"
#include "Text.h"
#include "SDL_mixer.h"

Map* CCore::oMap = new Map();
bool CCore::mouseLeftPressed = false;
bool CCore::mouseRightPressed = false;
int CCore::mouseX = 0;
int CCore::mouseY = 0;
bool CCore::quitGame = false;

bool CCore::movePressed = false;
bool CCore::keyMenuPressed = false;
bool CCore::keyS = false;
bool CCore::keyW = false;
bool CCore::keyA = false;
bool CCore::keyD = false;
bool CCore::keyShift = false;
bool CCore::keyAPressed = false;
bool CCore::keyDPressed = false;

CCore::CCore(void) {
    
}