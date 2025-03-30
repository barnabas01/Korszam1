#include <iostream>
#include <cmath>

template<typename T>
struct Vector2
{
    T x, y;

    T length()
    {
        return sqrt(x*x+y*y);
    }
    Vector2<T> normalize()
    {
        return *this/sqrt(x*x+y*y);
    }
    Vector2& operator+=(Vector2 const& v)
    {
        x+=v.x;
        y+=v.y;
        return *this;
    }
    Vector2& operator-=(Vector2 const& v)
    {
        x-=v.x;
        y-=v.y;
        return *this;
    }
};

template<typename T>
Vector2<T> operator+(Vector2<T> const& a, Vector2<T> const& b)
{
    return Vector2<T>{a.x+b.x, a.y+b.y};
}
template<typename T>
Vector2<T> operator-(Vector2<T> const& a, Vector2<T> const& b)
{
    return Vector2<T>{a.x-b.x, a.y-b.y};
}
template<typename T,typename D>
Vector2<T> operator*(D const& a, Vector2<T> const& b)
{
    return Vector2<T>{a*b.x, a*b.y};
}
template<typename T,typename D>
Vector2<T> operator*(Vector2<T> const& b, D const& a)
{
    return Vector2<T>{a*b.x, a*b.y};
}
template<typename T,typename D>
Vector2<T> operator/(Vector2<T> const& b, D const& a)
{
    return Vector2<T>{b.x/a, b.y/a};
}
template<typename T>
Vector2<T> operator*(Vector2<T> const& a, Vector2<T> const& b)
{
    return a.x*b.x + a.y*b.y;
}

template<typename T>
std::ostream& operator<<(std::ostream& o, Vector2<T> const& v)
{
    o<<"("<<v.x<<", "<<v.y<<")";
    return o;
}
template<typename T>
std::istream& operator>>(std::istream& i, Vector2<T>& v)
{
    i>>v.x;
    i>>v.y;
    return i;
}