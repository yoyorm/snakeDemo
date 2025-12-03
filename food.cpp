#include "food.h"
#include "position.h"
#include "snake.h"
#include <stdlib.h>
#include <time.h>
position Food::print() const
{
    return pos;
}

// 随机生成食物，保证不和蛇重合
void Food::randomGenerate(int width, int height, const Snake &snake)
{
    int x, y;
    bool cover = false;
    do
    {
        srand((unsigned int)time(NULL));
        cover = false;
        x = rand() % (width - 2) + 1;
        y = rand() % (height - 2) + 1;
        for (auto i : snake.print())
        {
            if (i.x == x && i.y == y)
            {
                cover = true;
                break;
            }
        }
    } while (cover);
    pos.x = x;
    pos.y = y;
    foodlist.push_back(pos);
}

void Food::deleteFood(const position &pos)
{
    for (auto i = foodlist.begin(); i != foodlist.end(); i++)
    {
        if (i->x == pos.x && i->y == pos.y)
        {
            foodlist.erase(i);
            break;
        }
    }
}

deque<position> Food::printList() const
{
    return foodlist;
}