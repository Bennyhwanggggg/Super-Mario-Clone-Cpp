#include "MenuManager.h"
#include "Core.h"

MenuManager::MenuManager(void) {
    this->currentGameState = eMainMenu;
    this->oMainMenu = new MainMenu();
    this->oLoadingMenu = new LoadingMenu();
    this->oAboutMenu = new AboutMenu();
    this->oOptionsMenu = new OptionsMenu();
    this->oPauseMenu = new PauseMenu();
}

MenuManager::~MenuManager(void) {
    delete activeOption;
    delete oMainMenu;
    delete oLoadingMenu;
    delete oAboutMenu;
}

void MenuManager::Update() {
    switch (currentGameState)
    {
    case eMainMenu:
        oMainMenu->Update();
        CCore::getMap()->UpdateBlocks();
        break;
    case eGameLoading:
        oLoadingMenu->Update();
        break;
    case eGame:
        CCore::getMap()->Update();
        CCore::getMap()->UpdateMinionsCollisions();
        break;
    case eAbout:
        CCore::getMap()->UpdateMinions();
        CCore::getMap()->UpdateMinionBlokcs();
		CCore::getMap()->UpdateBlocks();
		oAboutMenu->Update();
		break;
	case eOptions:
		oOptionsMenu->Update();
		break;
	case ePasue:
		oPauseMenu->Update();
		break;
    default:
        break;
    }
}

void MenuManager::Draw(SDL_Renderer* rR) {
	switch(currentGameState) {
		case eMainMenu:
			CCore::getMap()->DrawMap(rR);
			CCore::getMap()->getPlayer()->Draw(rR);
			CCore::getMap()->DrawGameLayout(rR);
			oMainMenu->Draw(rR);
			break;
		case eGameLoading:
			oLoadingMenu->Draw(rR);
			break;
		case eGame:
			CCore::getMap()->Draw(rR);
			break;
		case eAbout:
			CCore::getMap()->DrawMap(rR);
			CCore::getMap()->DrawMinions(rR);
			oAboutMenu->Draw(rR);
			break;
		case eOptions:
			CCore::getMap()->DrawMap(rR);
			CCore::getMap()->DrawMinions(rR);
			CCore::getMap()->getPlayer()->Draw(rR);
			CCore::getMap()->DrawGameLayout(rR);
			oOptionsMenu->Draw(rR);
			break;
		case ePasue:
			CCore::getMap()->DrawMap(rR);
			CCore::getMap()->DrawMinions(rR);
			CCore::getMap()->getPlayer()->Draw(rR);
			CCore::getMap()->DrawGameLayout(rR);
			oPauseMenu->Draw(rR);
			break;
        default:
            break;
	}
}

void MenuManager::setBackgroundColor(SDL_Renderer* rR) {
	switch(currentGameState) {
		case eMainMenu:
			CCore::getMap()->setBackgroundColor(rR);
			break;
		case eGameLoading:
			SDL_SetRenderDrawColor(rR, 0, 0, 0, 255);
			break;
		case eGame:
			CCore::getMap()->setBackgroundColor(rR);
			break;
		case eAbout:
			oAboutMenu->setBackgroundColor(rR);
			break;
	}
}

void MenuManager::enter() {
	switch(currentGameState) {
		case eMainMenu:
			oMainMenu->enter();
			break;
		case eGame:
			CCore::getMap()->setDrawLines(!CCore::getMap()->getDrawLines());
			break;
		case eAbout:
			oAboutMenu->enter();
			break;
		case eOptions:
			oOptionsMenu->enter();
			break;
		case ePasue:
			oPauseMenu->enter();
			break;
	}
}


void MenuManager::escape() {
	switch(currentGameState) {
		case eGame:
			
			break;
		case eAbout:
			oAboutMenu->enter();
			break;
		case eOptions:
			oOptionsMenu->escape();
			break;
		case ePasue:
			oPauseMenu->escape();
			break;
		case eMainMenu:
			oMainMenu->escape();
			break;
	}
}

void MenuManager::setKey(int keyID) {
	switch(currentGameState) {
		case eOptions:
			oOptionsMenu->setKey(keyID);
			break;
	}
}

void MenuManager::keyPressed(int iDir) {
	switch(currentGameState) {
		case eMainMenu:
			oMainMenu->updateActiveButton(iDir);
			break;
		case eOptions:
			oOptionsMenu->updateActiveButton(iDir);
			break;
		case ePasue:
			oPauseMenu->updateActiveButton(iDir);
			break;
	}
}

void MenuManager::resetActiveOptionID(gameState ID) {
	switch(ID) {
		case eMainMenu:
			oMainMenu->activeMenuOption = 0;
			break;
		case eOptions:
			oOptionsMenu->activeMenuOption = 0;
			break;
		case ePasue:
			oPauseMenu->activeMenuOption = 0;
			break;
	}
}

/* ******************************************** */

int MenuManager::getViewID() {
	return currentGameState;
}

void MenuManager::setViewID(gameState viewID) {
	this->currentGameState = viewID;
}

CIMG* MenuManager::getActiveOption() {
	return activeOption;
}

void MenuManager::setActiveOption(SDL_Renderer* rR) {
	activeOption = new CIMG("active_option", rR);
}

LoadingMenu* MenuManager::getLoadingMenu() {
	return oLoadingMenu;
}

AboutMenu* MenuManager::getAboutMenu() {
	return oAboutMenu;
}

OptionsMenu* MenuManager::getOptions() {
	return oOptionsMenu;
}