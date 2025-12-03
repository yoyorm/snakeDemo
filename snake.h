#ifndef SNAKE_H
#define SNAKE_H

#include "position.h"
#include <deque>
using namespace std;
class Snake
{
    private:
    deque<position> body;
    
    public:
    position last;//记录尾部最后一次消失位置，用于擦除和变长
    Snake();
    void move(const position &position);
    deque<position> print()const;
    void grow();
    
};

#endif