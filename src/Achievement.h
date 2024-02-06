
#ifndef RAYLIBSTARTER_ACHIEVEMENT_H
#define RAYLIBSTARTER_ACHIEVEMENT_H

#include <string>


class Achievement {
public:
    Achievement(std::string name, int unlockLevel);

    std::string getName();
    int getUnlockLevel();
    bool getLocked();
    void setLocked(bool locked);
protected:
    std::string name;
    int unlockLevel;
    bool locked = true;
};


#endif //RAYLIBSTARTER_ACHIEVEMENT_H
