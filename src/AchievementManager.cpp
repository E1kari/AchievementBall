
#include "AchievementManager.h"
#include "raylib.h"

AchievementManager::AchievementManager() {
    Achievement achievement("That's a hit!", 1);
    allAchivements.push_back(achievement);

    Achievement achievement2("Nice aim!", 5);
    allAchivements.push_back(achievement2);

    Achievement achievement3("Perfect aim!", 20);
    allAchivements.push_back(achievement3);

    Achievement achievement4("You're a true player!", 50);
    allAchivements.push_back(achievement4);

    Achievement achievement5("Why are you doing this to yourself?", 100);
    allAchivements.push_back(achievement5);

}

void AchievementManager::displayAchievements() {
    ClearBackground(WHITE);
    int textHeight = GetScreenHeight() - 100;
    for (Achievement achivement : allAchivements) {
        if( achivement.getLocked()) {
            DrawText(achivement.getName().c_str(), 10, textHeight, 100, LIGHTGRAY);
        }
        else {
            DrawText(achivement.getName().c_str(), 10, textHeight, 100, BLACK);
        }
        textHeight -= 200;
    }
}

void AchievementManager::updateAchievements() {
    int achivementIndex = 0;
    for (Achievement achivement : allAchivements) {
        if (achivement.getLocked() && achivement.getUnlockLevel() <= score.getScore()) {
            achivement.setLocked(false);
        }
    }
}
