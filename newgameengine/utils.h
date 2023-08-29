#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <string>
#include <cmath>
#include <algorithm>

enum rcode { FAIL = 0, OK = 1, NO_FILE = -1 };



template<class T>
class Vec2
{
public:
	//Vec2() = default;
	Vec2()
	{
		x = 0;
		y = 0;
	}
	Vec2(T x, T y) : x(x), y(y) {}

	~Vec2() = default;

	void Add(const Vec2& v) { x += v.x; y += v.y; };
	void Sub(const Vec2& v) { x -= v.x; y -= v.y; };
	void Scale(const T n) { x *= n; y *= n; };
	Vec2 Rotate(const T angle) const 
	{
		Vec2 result;  
		result.x = x * cos(angle) - y * sin(angle);
		result.y = x * sin(angle) + y * cos(angle);
		return result;
	};

	float Magnitude() const { return sqrtf(x * x + y * y); };
	float MagnitudeSquared() const { return (x * x + y * y); };

	Vec2& Normalize()
	{
		float length = Magnitude();
		if (length != 0.0f)
		{
			x /= length;
			y /= length;
		}
		return *this;
	}

	Vec2 UnitVector() const
	{
		Vec2 result = Vec2(0, 0);
		float length = Magnitude();
		if (length != 0.0f)
		{
			result.x = x / length;
			result.y = y / length;
		}
		return result;
	};

	Vec2 Normal() const { return Vec2(y, -x).Normalize(); };

	float Dot(const Vec2& v) const { return (x * v.x) + (y * v.y); };
	float Cross(const Vec2& v) const { return (x * v.y) - (y * v.x); };

	//overload operator
	Vec2& operator =(const Vec2& v) 
	{ 
		x = v.x; 
	    y = v.y; 
	return *this; 
	}

	bool operator ==(const Vec2& v) const { return x == v.x && y == v.y; };
	bool operator !=(const Vec2& v) const { return !(*this == v); };

	Vec2 operator +(const Vec2& v) const
	{
		Vec2 result;
		result.x = x + v.x;
		result.y = y + v.y;

		return result;
	};

	Vec2 operator -(const Vec2& v) const
	{
		Vec2 result;
		result.x = x - v.x;
		result.y = y - v.y;

		return result;
	};

	Vec2 operator *(const T n) const
	{
		Vec2 result;
		result.x = x * n;
		result.y = y * n;

		return result;
	};

	Vec2 operator /(const T n) const
	{
		Vec2 result;
		result.x = x / n;
		result.y = y / n;

		return result;
	};

	Vec2 operator -()
	{
		Vec2 result;
		result.x = x * -1;
		result.y = y * -1;
		return result;
	};

	Vec2& operator += (const Vec2& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	};

	Vec2& operator -=(const Vec2& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	};
	Vec2& operator *=(const T n)
	{
		x *= n;
		y *= n;
		return *this;
	};
	Vec2& operator /=(const T n)
	{
		x /= n;
		y /= n;
		return *this;
	};
		

public:
	T x, y;


};

typedef Vec2<int32_t> vi2d;
typedef Vec2<uint32_t> vu2d;
typedef Vec2<float> vf2d;
typedef Vec2<double> vd2d;



#endif // !UTILS>H

