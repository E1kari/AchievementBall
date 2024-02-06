//
// Created by Josi on 01.02.2024.
//

#ifndef RAYLIBSTARTER_SCORE_H
#define RAYLIBSTARTER_SCORE_H


class Score {
public:
    int getScore();
    int getLevel();

    void updateScore(int scoreToAdd);
    void updateLevel();

private:
    int score = 0;
    int level = 0;
};


#endif //RAYLIBSTARTER_SCORE_H
