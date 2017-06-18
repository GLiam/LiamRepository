#include "Vector3.h"
#include <cmath>

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(const float a_FX, const float a_FY, const float a_FZ)
{
	x = a_FX;
	y = a_FY;
	z = a_FZ;
}

Vector3 Vector3::operator+(const Vector3 & a_RHS) const
{
	return Vector3(x + a_RHS.x, y + a_RHS.y, z + a_RHS.z);
}

Vector3 Vector3::operator-(const Vector3 & a_RHS) const
{
	return Vector3(x - a_RHS.x, y - a_RHS.y, z - a_RHS.z);
}

Vector3 Vector3::operator*(const float & a_RHS) const
{
	return Vector3(x * a_RHS, y * a_RHS, z * a_RHS);
}

Vector3 Vector3::operator/(const float & a_RHS) const
{
	return Vector3(x / a_RHS, y / a_RHS, z / a_RHS);
}

float Vector3::dot(Vector3 V3)
{
	float a_x = this->x * V3.x;
	float a_y = this->y * V3.y;
	float a_z = this->z * V3.z;

	return a_x + a_y + a_z;
}

void Vector3::Scale(const float & a_fScale)
{
	this->x *= a_fScale;
	this->y *= a_fScale;
	this->z *= a_fScale;
}

void Vector3::Translate(const Vector3 & a_v3Translation)
{
	this->x *= a_v3Translation.x;
	this->y *= a_v3Translation.y;
	this->z *= a_v3Translation.z;
}

float Vector3::magnitude()
{
	return sqrtf(SqrMagnitude());
}

float Vector3::SqrMagnitude()
{
	return((x * x) + (y * y) + (z * z));
}

float Vector3::normalise()
{
	float fMag = magnitude();
	if (fMag != 0)
	{
		x /= fMag;
		y /= fMag;
		z /= fMag;
	}
	return x + y;
}

Vector3 Vector3::cross( const Vector3 & a_V1) const
{
	Vector3 NewVector;

	NewVector.x = (y * a_V1.z) - (z * a_V1.y);
	NewVector.y = (z * a_V1.x) - (x * a_V1.z);
	NewVector.z = (x * a_V1.y) - (y * a_V1.x);

	return NewVector;
}

float& Vector3::operator[](int a_i)
{
	return data[a_i];
}

Vector3::operator float *()
{
	return data;
}