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
    this->quitGame = false;
    this->iFPS = 0;
    this->iNumOfFPS = 0;
    this->lFPSTime = 0;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);

    window = SDL_CreateWindow("Super Mario!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, CCFG::GAME_WIDTH, CCFG::GAME_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        quitGame = true;
    }

    rR = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // ----- ICO
    std::string filename = "files/images/ico.bmp";
    SDL_Surface* loadedSurface = SDL_LoadBMP(filename.c_str());
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));

    SDL_SetWindowIcon(window, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    mainEvent = new SDL_Event();
    // ----- ICO

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    oMap = new Map(rR);
    CCFG::getMM()->setActiveOption(rR);
    CCFG::getSMBLOGO()->setIMG("super_mario_bros", rR);

    CCFG::getMusic()->PlayMusic();

    this->keyMenuPressed = this->movePressed = this->keyS = this->keyW = this->keyA = this->keyD = this->keyShift = false;
    this->keyAPressed = this->keyDPressed = this->firstDir = false;
    this->mouseX = this->mouseY = 0;

    CCFG::keyIDA = SDLK_a;
    CCFG::keyIDS = SDLK_s;
    CCFG::keyIDD = SDLK_d;
    CCFG::keyIDSpace = SDLK_SPACE;
    CCFG::keyIDShift = SDLK_LSHIFT;
}