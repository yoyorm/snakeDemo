
#include "snake.h"

Snake::Snake()
{
    body.push_front(position{25, 10});
    body.push_front(position{24, 10});
    body.push_front(position{23, 10});
}

void Snake::move(const position &pos)
{
    body.push_front(pos);
    last=body.back();
    body.pop_back();
}

deque<position> Snake::print()const
{
    return body;
}

void Snake::grow()
{
    body.push_back(last);
}

bool Snake::isCollision() const
{
    for(int i=1;i<body.size();i++)
    {
        if(body[0].x==body[i].x && body[0].y==body[i].y)
        {
            return true;
        }
    }
    return false;
}