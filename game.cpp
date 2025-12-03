#include <windows.h>
#include "game.h"
#include "position.h"
#include "snake.h"
#include <conio.h>
#include <iostream>
using namespace std;

static const int W = 40, H = 20;

// 实现写入光标位置
void setCursorPosition(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
// 写入字符
void drawChar(int x, int y, char c)
{
    setCursorPosition(x, y);
    cout << c;
}

// game初始化
void Game::init()
{
    // 画边框（只画一次）
    for (int x = 0; x < W; ++x)
    {
        drawChar(x, 0, '#');
        drawChar(x, H - 1, '#');
    }
    for (int y = 0; y < H; ++y)
    {
        drawChar(0, y, '#');
        drawChar(W - 1, y, '#');
    }
    // 其余状态默认构造里已就绪
    nowpos = position{25, 10};
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
}

// 绘制画面
void Game::render()
{
    drawChar(snake.last.x, snake.last.y, ' ');
    for (auto pos : snake.print())
    {
        drawChar(pos.x, pos.y, 'O');
    }

    setCursorPosition(WIDTH + 3, 0);
    cout << "NowPos:" << nowpos.x << " " << nowpos.y << "  ";
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