//
// Created by Josi on 01.02.2024.
//

#include "Score.h"

int Score::getScore() {
    return score;
}

int Score::getLevel() {
    return level;
}

void Score::updateScore(int scoreToAdd) {
    score += scoreToAdd;
}

void Score::updateLevel() {
    if (score % 5 == 0) {
        level++;
    }
}

