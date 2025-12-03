#include "game.h"
using namespace std;

int main()
{
    Game game(40, 20);//初始化游戏边界大小
    game.run();
    game.gameOver();
    return 0;
}