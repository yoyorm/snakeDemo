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
    position last;
    Snake();
    void move(const position &position);
    deque<position> print()const;
    
};

#endif