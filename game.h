#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "position.h"
#include "food.h"

class Game
{
private:
    Snake snake;
    Food food;
    int WIDTH=20;
    int HEIGHT=10;
    position oldpos;
    position nowpos;
    int dx,dy;
    int score=0;
    bool isGameOver=false;
    bool foodGenerated=false;
    bool snakeGrow=false;

public:
    Game(int width, int height);
    void run();
    void init();
    void processInput();
    void update();
    void render();
    void gameOver();
};

#endif