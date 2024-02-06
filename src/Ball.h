

#ifndef RAYLIBSTARTER_BALL_H
#define RAYLIBSTARTER_BALL_H


#include "raylib.h"

class Ball {
public:
    Ball();
    ~Ball();

    int getHitCooldown();

    int positionUpdate();
    bool checkCollision();
    void draw(bool beingHit);

private:
    Vector2 position;
    Vector2 velocity;
    Texture2D ballTexture;
    int hitCooldown;
};


#endif //RAYLIBSTARTER_BALL_H
