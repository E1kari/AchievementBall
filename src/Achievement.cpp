
#include "Achievement.h"


Achievement::Achievement(std::string _name, int _unlockLevel) {
    name = _name;
    unlockLevel = _unlockLevel;
    locked = true;
}

std::string Achievement::getName() {
    return name;
}

int Achievement::getUnlockLevel() {
    return unlockLevel;
}

bool Achievement::getLocked() {
    return locked;
}

void Achievement::setLocked(bool _locked) {
    locked = _locked;
}

