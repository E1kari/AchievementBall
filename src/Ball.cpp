#include "Ball.h"
#include "raylib.h"

int Ball::positionUpdate() {
    int colorJump = 0;

    // Ball movement
    if (this->position.x >= GetScreenWidth() - ballTexture.width || position.x <= 0) {
        this->velocity.x *= -1;
        colorJump++;
    }

    if (this->position.y >= GetScreenHeight() - ballTexture.height || this->position.y <= 0) {
        this->velocity.y *= -1;
        colorJump++;
    }


    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;

    return colorJump;
}

bool Ball::checkCollision() {
    hitCooldown--;
    if (CheckCollisionPointCircle(GetMousePosition(),
                                  {(this->position.x + ballTexture.width / 2), (this->position.y + ballTexture.height / 2)},
                                  (float) ballTexture.width / 2) && IsMouseButtonPressed(0)) {
        hitCooldown = 10;
        return true;
    }
    return false;
}

int Ball::getHitCooldown() {
    return hitCooldown;
}

void Ball::draw(bool hit) {
    if (hit) {
        DrawTexture(ballTexture, this->position.x, this->position.y, MAROON);
    }
    else {
        DrawTexture(ballTexture, this->position.x, this->position.y, BLACK);
    }
}

Ball::Ball() {
    ballTexture = LoadTexture("assets/graphics/testimageW.png");
    position = {10, 100};
    velocity = {10.0f, 10.0f};
    hitCooldown = 0;
}

Ball::~Ball() {
    UnloadTexture(ballTexture);
}
