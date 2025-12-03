#ifndef POSITION_H
#define POSITION_H

struct position
{
    int x;
    int y;
    bool operator==(const position &other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator!=(const position &other) const
    {
        return x != other.x || y != other.y;
    }
};
#endif