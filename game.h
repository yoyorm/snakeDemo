#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "position.h"

class Game
{
private:
    Snake snake;
    const int WIDTH = 50;
    const int HEIGHT = 20;
    position oldpos;
    position nowpos;
    int dx,dy;
    bool gameOver=false;

public:
    void run();
    void init();
    void processInput();
    void update();
    void render();
};

#endif