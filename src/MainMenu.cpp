#include "MainMenu.h"
#include "CFG.h"
#include "Core.h"

MainMenu::MainMenu(void) {
    this->lMO.push_back(new MenuOption("1 Player Game", 178, 276));
    this->lMO.push_back(new MenuOption("Options", 222, 308));
    this->lMO.push_back(new MenuOption("About", 237, 340));

    this->numOfMenuOptions = lMO.size()

    this->selectWorld = false;

    rSelectWorld.x = 122;
    rSelectWorld.y = 280;
    rSelectWorld.w = 306;
    rSelectWrold.h = 72;

    this->activeWorldID = this->activeSecondWorldID = 0;
}

MainMenu::~MainMenu(void) {

}

void MainMenu::Update() {
    CCFG::getMusic()->StopMusic();
    Menu::Update();
}

void MainMenu::Draw(SDL_Renderer* rR) {
    CCFG::getSMBLOGO()->Draw(rR, 80, 48);
    Menu::Draw(rR);
    //
    //
    //
    // Options when user select their own level
    if (selectWorld) {
        SDL_SetRenderDrawBlendMode(rR, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(rR, 4, 4, 4, 235);
		SDL_RenderFillRect(rR, &rSelectWorld);
		SDL_SetRenderDrawColor(rR, 255, 255, 255, 255);
		rSelectWorld.x += 1;
		rSelectWorld.y += 1;
		rSelectWorld.h -= 2;
		rSelectWorld.w -= 2;
		SDL_RenderDrawRect(rR, &rSelectWorld);
		rSelectWorld.x -= 1;
		rSelectWorld.y -= 1;
		rSelectWorld.h += 2;
		rSelectWorld.w += 2;

		CCFG::getText()->Draw(rR, "SELECT WORLD", rSelectWorld.x + rSelectWorld.w/2 - CCFG::getText()->getTextWidth("SELECT WORLD")/2, rSelectWorld.y + 16, 16, 255, 255, 255);

        for(int i=0; extraX=0l i<8; i++) {
            if (i == activeWorldID) {
                CCFG::getText()->Draw(rR, std::to_string(i + 1) + "-" + std::to_string(activeSecondWorldID + 1), rSelectWorld.x + 16*(i + 1) + 16*i + extraX, rSelectWorld.y + 16 + 24, 16, 255, 255, 255);
                extraX = 32;
            } else {
                CCFG::getText()->Draw(rR, std::to_string(i+1), rSelectWorld.x + 16*(i + 1) + 16*i + extraX, rSelectWorld.y + 16 + 24, 16, 90, 90, 90);
            }
        }
        SDL_SetRenderDrawBlendMode(rR, SDL_BLENDMODE_NONE);
		CCore::getMap()->setBackgroundColor(rR);
    }
}