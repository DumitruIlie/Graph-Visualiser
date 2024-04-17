// Ilie Dumitru
#ifndef VEC2_H
#define VEC2_H

#include<cmath>
#include<iostream>

template <class T>
class vec2
{
public:
    T x, y;

    vec2() : x(), y() {}
    vec2(T _x, T _y) : x(_x), y(_y) {}

    vec2<T> operator+(const vec2<T>& v) const
    {
    	return vec2<T>(this->x + v.x, this->y + v.y);
	}
    vec2<T> operator-(const vec2<T>& v) const
    {
    	return vec2<T>(this->x - v.x, this->y - v.y);
	}
    vec2<T> operator*(const T& s) const
    {
    	return vec2<T>(this->x * s, this->y * s);
	}
    friend vec2<T> operator*(const T& s, const vec2<T>& a)
    {
    	return vec2<T>(a.x * s, a.y * s);
	}
    vec2<T> operator/(const T& s) const
    {
    	if(s)
			return vec2<T>(this->x / s, this->y / s);
		return vec2<T>();
	}

    vec2<T> operator-() const
    {
    	return vec2<T>(-this->x, -this->y);
	}
    vec2<T> operator+() const
    {
    	return vec2<T>(+this->x, +this->y);
	}

    vec2<T>& operator+=(const vec2<T>& v)
    {
    	this->x += v.x;
    	this->y += v.y;
    	return *this;
	}
    vec2<T>& operator-=(const vec2<T>& v)
    {
    	this->x -= v.x;
    	this->y -= v.y;
    	return *this;
	}
    vec2<T>& operator*=(const T& s)
    {
    	this->x *= s;
    	this->y *= s;
    	return *this;
	}
    vec2<T>& operator/=(const T& s)
    {
    	if(s)
		{
			this->x /= s;
			this->y /= s;
		}
		else
			this->x = this->y = 0;
		return *this;
	}

	// Dot product
    T operator*(const vec2<T>& v) const
    {
    	return this->x * v.x + this->y * v.y;
	}
	// 2D Cross product
    T operator^(const vec2<T>& v) const
    {
    	return this->x * v.y - this->y * v.x;
	}
    bool operator==(const vec2<T>& v) const
    {
    	return this->x == v.x && this->y == v.y;
	}
    bool operator!=(const vec2<T>& v) const
    {
    	return this->x != v.x || this->y != v.y;
	}

    friend std::ostream& operator<<(std::ostream& out, const vec2<T>& v)
    {
    	return out << '(' << v.x << ", " << v.y << ')';
	}
    friend std::istream& operator>>(std::istream& in, vec2<T>& v)
    {
    	return in >> v.x >> v.y;
	}

    T lengthSquared() const
    {
    	return this->x * this->x + this->y * this->y;
	}
    T length() const
    {
    	return sqrt(this->x * this->x + this->y * this->y);
	}
    vec2<T>& normalize()
    {
    	return *this /= this->length();
	}
    vec2<T> normalized() const
    {
    	return *this / this->length();
	}
};

typedef vec2<int> vec2i;
typedef vec2<float> vec2f;
typedef vec2<double> vec2d;

#endif // VEC2_H