struct Vec2D
{
    int x;
    int y;

    vec2D(): x(0),y(0){}
    vec2D(int x, int y): x(x),y(y){}
    vec2D(const Vec2D& v): x(v.x), y(v.y){}

    Vec2D& operator += (vec2D&v)
    {
        return vec2D(x + v.x, y + v.y);
    }

     Vec2D& operator -= (vec2D&v)
    {
        return vec2D(x - v.x, y - v.y);
    }
};
