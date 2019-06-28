#pragma once // The pragma directive is used to access compiler-specific preprocessor extensions. A common use of #pragma is the #pragma once directive, which asks the compiler to include a header file only a single time, no matter how many times it has been imported

#ifndef CORE_H
#define CORE_H

#include "Map.h"

class CCore
{
private:
    SDL_Window* window;
    SDL_Renderer* rR;
    SDL_Event* mainEvent;

    // FPS
    long frameTime;
    static const int MIN_FRAME_TIME = 16;
    unsigned long lFPSTime;
    int iNumOfFPS, iFPS;

    // Input
    static bool movePressed;
    static bool keyMenuPressed;
    static bool keyS;
    static bool keyW;
    static bool keyA;
    static bool keyD;
    static bool keyShift;
    static bool keyAPressed;
    static bool keyDPressed;
    bool firstDir;

    static Map* oMap;

    // Methods
    void Input();
    void MouseInput();
    void InputPlayer();
    void InputMenu();

public:
    CCore(void);
    ~CCore(void); // Not CCore, ~ = BitWise Not

    static bool quitGame;

    void mainLoop();

    void Update();
    void Draw();
    
    void resetMove();
    static void resetKeys();

    static bool mouseLeftPressed;
    static bool mouseRightPressed;
    static int mouseX;
    static int mouseY;

    static Map* getMap();
};

#endif