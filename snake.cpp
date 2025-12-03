
#include "snake.h"

//默认出生点
Snake::Snake()
{
    body.push_front(position{25, 10});
    body.push_front(position{24, 10});
    body.push_front(position{23, 10});
}

Snake::Snake(const position &pos)
{
    body.push_front(pos);
    body.push_front(position{pos.x-1, pos.y});
    body.push_front(position{pos.x-2, pos.y});
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