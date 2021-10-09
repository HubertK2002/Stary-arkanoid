#pragma once
struct Vec2D
{
    int x;
    int y;

    Vec2D(): x(0),y(0){}
    Vec2D(int x, int y): x(x),y(y){}
    Vec2D(const Vec2D& v): x(v.x), y(v.y){}

    Vec2D& operator+=(Vec2D& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

     Vec2D& operator-=(Vec2D& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }
};
