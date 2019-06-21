#include "Event.h"
#include "Core.h"

Event::Event(void) {
    this->iDelay=0;
    this->newUnderWater = false;
    this->endGame = false;
    this->iTime = 0;
    this->bState = true;
    this->stepID = 0;
}

Event::~Event(void) {

}

