#include <cstdlib>
#include "raylib.h"
#include "config.h"
#include "Ball.h"
#include "Score.h"
#include "AchievementManager.h"


int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here

    Ball ball;
    Score score;
    AchievementManager achievementManager;
    ball.draw(false);


    Color allColors[] = {RED,ORANGE,YELLOW,GREEN,LIME,DARKGREEN,DARKBLUE,BLUE,SKYBLUE,PINK, PURPLE,VIOLET };
    int currentColorIndex = 0;


    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        int colorJump = 0;

        colorJump = ball.positionUpdate();
        if(ball.checkCollision()) {
            score.updateScore(1);
            score.updateLevel();
        }

        if(CheckCollisionPointRec(GetMousePosition(), {static_cast<float>(GetScreenWidth() - 75), 0, 75, 75})) {
            if (IsMouseButtonPressed(0)) {
                achievementManager.displayAchievements();
            }
        }

        while (colorJump > 0) {
            currentColorIndex++;

            if (currentColorIndex == (sizeof(allColors) / sizeof(allColors[0]))) {
                currentColorIndex = 0;
            }

            colorJump--;
        }


        BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()

            ClearBackground(allColors[currentColorIndex]);
            if (ball.getHitCooldown() >= 0) {
                ball.draw(true);
            }
            else {
                ball.draw(false);
            }
        DrawText(TextFormat("Level: %i\nScore: %i", score.getLevel(), score.getScore()), 10, 10, 30, LIGHTGRAY);
        DrawRectangle(GetScreenWidth() - 75, 0, 75, 75, GRAY);

        EndDrawing();
    } // Main game loop end


    // De-initialization here

    ball.~Ball();

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
