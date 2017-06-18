#include "Vector2.h"
#include <cmath>


Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float a_FX, float a_FY)
{
	x = a_FX;
	y = a_FY;
}

Vector2 Vector2::operator+(const Vector2& a_RHS) const
{
	return Vector2(x + a_RHS.x, y + a_RHS.y);
}

Vector2 Vector2::operator-(const Vector2& a_RHS) const
{
	return Vector2(x - a_RHS.x, y - a_RHS.y);
}

Vector2 Vector2::operator*(const float& a_RHS) const
{
	return Vector2(x * a_RHS, y * a_RHS);
}

Vector2 Vector2::operator/(const float & a_RHS) const
{
	return Vector2(x / a_RHS, y / a_RHS);
}

float Vector2::dot(Vector2 V2)
{
	float a_x = this->x * V2.x;
	float a_y = this->y * V2.y;

	return a_x + a_y;
}

void Vector2::Scale(const float & a_fScale)
{
	this->x *= a_fScale;
	this->y *= a_fScale;
}

void Vector2::Translate(const Vector2 & a_v2Translation)
{
	this->x *= a_v2Translation.x;
	this->y *= a_v2Translation.y;
}

float Vector2::magnitude()
{
	return sqrtf(SqrMagnitude());
}

float Vector2::SqrMagnitude()
{
	return((x *x) + (y * y));
}

float Vector2::normalise()
{
	float fMag = magnitude();
	if (fMag != 0)
	{
		x /= fMag;
		y /= fMag;
	}
	return x + y;
}

float& Vector2::operator[](int a_i)
{
	return data[a_i];
}

Vector2::operator float*()
{
	return data;
}