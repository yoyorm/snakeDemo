#include <windows.h>
#include "game.h"
#include "position.h"
#include "snake.h"
#include "food.h"
#include <conio.h>
#include <iostream>
using namespace std;

// 实现写入光标位置
void setCursorPosition(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
// 写入字符
void drawChar(short x, short y, char c)
{
    setCursorPosition(x, y);
    cout << c;
}

// game初始化
void Game::init()
{
    // 画边框（只画一次）
    for (int x = 0; x < WIDTH; ++x)
    {
        drawChar(x, 0, '#');
        drawChar(x, HEIGHT - 1, '#');
    }
    for (int y = 0; y < HEIGHT; ++y)
    {
        drawChar(0, y, '#');
        drawChar(WIDTH - 1, y, '#');
    }
    
    nowpos = position{25, 10};
}

Game::Game(int width, int height)
{
    WIDTH = width;
    HEIGHT = height;
}

void Game::processInput()
{
    if (_kbhit())
    {
        oldpos = nowpos;
        char c = _getch();
        if (c == 'w' && dy != -1)
        {
            dx = 0;
            dy = 1;
            nowpos.y--;
        }
        if (c == 's' && dy != 1)
        {
            dx = 0;
            dy = -1;
            nowpos.y++;
        }
        if (c == 'a' && dx != 1)
        {
            dx = -1;
            dy = 0;
            nowpos.x--;
        }
        if (c == 'd' && dx != -1)
        {
            dx = 1;
            dy = 0;
            nowpos.x++;
        }
    }
}

// 更新蛇状态
void Game::update()
{
    if (nowpos != oldpos)
    {
        oldpos = nowpos;
        snake.move(nowpos);
    }

    // 食物生成并且设置间隔
    static int count = 0;
    if (count++ % 25 == 0)
    {
        food.randomGenerate(WIDTH, HEIGHT, snake);
        foodGenerated = true;
    }
    else
    {
        foodGenerated = false;
    }

    for (auto pos : food.printList())
    {
        snakeGrow = false;
        if (nowpos == pos)
        {
            food.deleteFood(pos);
            snake.grow();
            score++;
            snakeGrow = true;
            break;
        }
    }
}

// 绘制画面
void Game::render()
{
    // 清除蛇尾
    if (!snakeGrow)
        drawChar(snake.last.x, snake.last.y, ' ');
    // 画蛇
    for (auto pos : snake.print())
    {
        drawChar(pos.x, pos.y, 'O');
    }
    // 画食物
    if (foodGenerated)
        drawChar(food.print().x, food.print().y, '*');
    // 显示蛇头位置
    setCursorPosition(WIDTH + 3, 0);
    cout << "NowPos: " << nowpos.x << " " << nowpos.y << "  ";
    //显示分数
    setCursorPosition(WIDTH + 3, 1);
    cout << "Score: " << score << "  ";

    setCursorPosition(WIDTH + 3, HEIGHT);
    cout << "snake game Made by @yoyorm";
}

void Game::run()
{
    init();
    while (!gameOver)
    {
        processInput();
        update();
        render();
        Sleep(150);
    }
}