
#ifndef RAYLIBSTARTER_ACHIEVEMENTMANAGER_H
#define RAYLIBSTARTER_ACHIEVEMENTMANAGER_H

#include "Achievement.h"
#include <vector>
#include "Score.h"

class AchievementManager {
public:
    AchievementManager();

    void unlockAchievement(Achievement achivement);
    void displayAchievements();
    void updateAchievements();
protected:
    std::vector<Achievement> allAchivements;
    Score score;
};


#endif //RAYLIBSTARTER_ACHIEVEMENTMANAGER_H
