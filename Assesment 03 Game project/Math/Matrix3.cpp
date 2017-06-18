#include "Matrix3.h"
#include <cmath>


Matrix3::Matrix3()
{
	m00 = 1;
	m01 = 0;
	m02 = 0;

	m10 = 0;
	m11 = 1;
	m12 = 0;

	m20 = 0;
	m21 = 0;
	m22 = 1;
}

Matrix3::Matrix3(const float a_m00, const float a_m01, const float a_m02, const float a_m10, const float a_m11, const float a_m12, const float a_m20, const float a_m21, const float a_m22)
{
	m00 = a_m00;
	m01 = a_m01;
	m02 = a_m02;
	m10 = a_m10;
	m11 = a_m11;
	m12 = a_m12;
	m20 = a_m20;
	m21 = a_m21;
	m22 = a_m22;
}

Vector3 Matrix3::operator*(const Vector3 & a_RHS)
{
	return Vector3
	(m00 * a_RHS.x + m10 * a_RHS.y + m20 * a_RHS.z,
	 m01 * a_RHS.x + m11 * a_RHS.y + m21 * a_RHS.z,
	 m02 * a_RHS.x + m12 * a_RHS.y + m22 * a_RHS.z);
}

Matrix3 Matrix3::operator*(const Matrix3 & a_RHS)
{
	return Matrix3(
		m00 * a_RHS.m00 + m10 * a_RHS.m01 + m20 * a_RHS.m02,
		m01 * a_RHS.m00 + m11 * a_RHS.m01 + m21 * a_RHS.m02,
		m02 * a_RHS.m00 + m12 * a_RHS.m01 + m22 * a_RHS.m02,
		m00 * a_RHS.m10 + m10 * a_RHS.m11 + m20 * a_RHS.m12,
		m01 * a_RHS.m10 + m11 * a_RHS.m11 + m21 * a_RHS.m12,
		m02 * a_RHS.m10 + m12 * a_RHS.m11 + m22 * a_RHS.m12,
		m00 * a_RHS.m20 + m10 * a_RHS.m12 + m20 * a_RHS.m22,
		m01 * a_RHS.m20 + m11 * a_RHS.m12 + m21 * a_RHS.m22,
		m02 * a_RHS.m20 + m12 * a_RHS.m12 + m22 * a_RHS.m22);
}

Vector3 & Matrix3::operator[](int a_i)
{
	return m_V3Data[a_i];
}

Matrix3::operator float*()
{
	return data;
}

void Matrix3::setRotate(const float a_fRotation)
{
	setRotateZ(a_fRotation);
}

void Matrix3::setRotateX(const float a_fRotation)
{
	m00 = 1;

	m11 = cos(a_fRotation);
	m12 = sin(a_fRotation);

	m21 = -sin(a_fRotation);
	m22 = cos(a_fRotation);

}

void Matrix3::setRotateY(const float a_fRotation)
{
	m00 = cos(a_fRotation);

	m02 = -sin(a_fRotation);

	m11 = 1;


	m20 = sin(a_fRotation);

	m22 = cos(a_fRotation);
}

void Matrix3::setRotateZ(const float a_fRotation)
{
	m00 = cos(a_fRotation);
	m01 = sin(a_fRotation);


	m10 = -sin(a_fRotation);
	m11 = cos(a_fRotation);

	m22 = 1;
}