#ifndef FOOD_H
#define FOOD_H
#include "position.h"
#include "snake.h"
#include <deque>
class Food
{
private:
    position pos;
    deque<position> foodlist;

public:
    void randomGenerate(int width, int height,const Snake &snake);
    position print() const;
    deque<position> printList() const;
    void deleteFood(const position &pos);
};

#endif