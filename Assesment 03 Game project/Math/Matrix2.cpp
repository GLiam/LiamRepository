#include "Matrix2.h"
#include <cmath>

Matrix2::Matrix2()
{
	m00 = 1;
	m01 = 0;
	m10 = 0;
	m11 = 1;
}

Matrix2::Matrix2(const float a_m00, const float a_m01, const float a_m10, const float a_m11)
{
	m00 = a_m00;
	m01 = a_m01;
	m10 = a_m10;
	m11 = a_m11;
}

Vector2 Matrix2::operator*(const Vector2 & a_RHS)
{
	//return Vector2(data[0] * a_V2.x + data[2] * a_V2.y,
	//			   data[1] * a_V2.x + data[3] * a_V2.y);

	return Vector2(m00 * a_RHS.x + m10 * a_RHS.y,
				   m01 * a_RHS.x + m11 * a_RHS.y);

}

Matrix2 Matrix2::operator*(const Matrix2 & a_RHS)
{
	return Matrix2
	( m00 * a_RHS.m00 + m10 * a_RHS.m01,  // m00
	  m01 * a_RHS.m00 + m11 * a_RHS.m01,  // m01
	  m00 * a_RHS.m10 + m10 * a_RHS.m11,  // m10
	  m01 * a_RHS.m10 + m11 * a_RHS.m11); // m11
}

Vector2 & Matrix2::operator[](int a_i)
{
	return m_V2Data[a_i];
}

Matrix2::operator float*()
{
	return data;
}

void Matrix2::setRotate(const float a_fRotation)
{
	m00 = cos(a_fRotation);
	m01 = sin(a_fRotation);
	m10 = -sin(a_fRotation);
	m11 = cos(a_fRotation);
}
