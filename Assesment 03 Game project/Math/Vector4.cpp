#include "Vector4.h"
#include <cmath>


Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(const float a_FX, const float a_FY, const float a_FZ, const float a_FW)
{
	x = a_FX;
	y = a_FY;
	z = a_FZ;
	w = a_FW;

}

Vector4 Vector4::operator+(const Vector4 & a_RHS) const
{
	return Vector4(x + a_RHS.x, y + a_RHS.y, z + a_RHS.z, w + a_RHS.w);
}

Vector4 Vector4::operator-(const Vector4 & a_RHS) const
{
	return Vector4(x - a_RHS.x, y - a_RHS.y, z - a_RHS.z, w - a_RHS.w);
}

Vector4 Vector4::operator*(const float & a_RHS) const
{
	return Vector4(x * a_RHS, y * a_RHS, z * a_RHS, w * a_RHS);
}

Vector4 Vector4::operator/(const float & a_RHS) const
{
	return Vector4(x / a_RHS, y / a_RHS, z / a_RHS, w / a_RHS);
}

float Vector4::dot(Vector4 V4)
{
	float a_x = this->x * V4.x;
	float a_y = this->y * V4.y;
	float a_z = this->z * V4.z;
	float a_w = this->w * V4.w;

	return a_x + a_y + a_z + a_w;
}

void Vector4::Scale(const float & a_fScale)
{
	this->x *= a_fScale;
	this->y *= a_fScale;
	this->z *= a_fScale;
	this->w *= a_fScale;
}

void Vector4::Translate(const Vector4 & a_v4Translation)
{
	this->x *= a_v4Translation.x;
	this->y *= a_v4Translation.y;
	this->z *= a_v4Translation.z;
	this->w *= a_v4Translation.w;
}

float Vector4::magnitude()
{
	return sqrtf(SqrMagnitude());
}

float Vector4::SqrMagnitude()
{
	return ((x * x) + (y * y) + (z * z) + (w * w));
}

float Vector4::normalise()
{
	float fMag = magnitude();
	if (fMag != 0)
	{
		x /= fMag;
		y /= fMag;
		z /= fMag;
		w /= fMag;
	}
	return x + y;
}

Vector4 Vector4::cross(const Vector4 & a_V1) const
{
	Vector4 NewVector;

	NewVector.x = ((y * a_V1.z) - (z * a_V1.y));
	NewVector.y = ((z * a_V1.x) - (x * a_V1.z));
	NewVector.z = ((x * a_V1.y) - (y * a_V1.x));
	NewVector.w = 0.0;

	return NewVector;
}

float & Vector4::operator[](int a_i)
{
	return data[a_i];
}

Vector4::operator float*()
{
	return data;
}