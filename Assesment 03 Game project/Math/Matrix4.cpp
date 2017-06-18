#include "Matrix4.h"
#include <cmath>

Matrix4::Matrix4()
{
	m00 = 1;
	m01 = 0;
	m02 = 0;
	m03 = 0;

	m10 = 0;
	m11 = 1;
	m12 = 0;
	m13 = 0;

	m20 = 0;
	m21 = 0;
	m22 = 1;
	m23 = 0;

	m30 = 0;
	m31 = 0;
	m32 = 0;
	m33 = 1;
}

Matrix4::Matrix4(const float a_m00, const float a_m01, const float a_m02, const float a_m03, const float a_m10, const float a_m11, const float a_m12, const float a_m13, const float a_m20, const float a_m21, const float a_m22, const float a_m23, const float a_m30, const float a_m31, const float a_m32, const float a_m33)
{
	m00 = a_m00;
	m01 = a_m01;
	m02 = a_m02;
	m03 = a_m03;
	m10 = a_m10;
	m11 = a_m11;
	m12 = a_m12;
	m13 = a_m13;
	m20 = a_m20;
	m21 = a_m21;
	m22 = a_m22;
	m23 = a_m23;
	m30 = a_m30;
	m31 = a_m31;
	m32 = a_m32;
	m33 = a_m33;
}

Vector4 Matrix4::operator*(const Vector4 & a_RHS)
{
	return Vector4(
	m00 * a_RHS.x + m10 * a_RHS.y + m20 * a_RHS.z + m30 * a_RHS.w,
	m01 * a_RHS.x + m11 * a_RHS.y + m21 * a_RHS.z + m31 * a_RHS.w,
	m02 * a_RHS.x + m12 * a_RHS.y + m22 * a_RHS.z + m32 * a_RHS.w,
	m03 * a_RHS.x + m13 * a_RHS.y + m23 * a_RHS.z + m33 * a_RHS.w);
}

Matrix4 Matrix4::operator*(const Matrix4 & a_RHS)
{
	return Matrix4(
	m00 * a_RHS.m00 + m10 * a_RHS.m01 + m20 * a_RHS.m02 + m30 * a_RHS.m03,
	m01 * a_RHS.m00 + m11 * a_RHS.m01 + m21 * a_RHS.m02 + m31 * a_RHS.m03,
	m02 * a_RHS.m00 + m12 * a_RHS.m01 + m22 * a_RHS.m02 + m32 * a_RHS.m03,
	m03 * a_RHS.m00 + m13 * a_RHS.m01 + m23 * a_RHS.m02 + m33 * a_RHS.m03,
	m00 * a_RHS.m10 + m10 * a_RHS.m11 + m20 * a_RHS.m12 + m30 * a_RHS.m13,
	m01 * a_RHS.m10 + m11 * a_RHS.m11 + m21 * a_RHS.m12 + m31 * a_RHS.m13,
	m02 * a_RHS.m10 + m12 * a_RHS.m11 + m22 * a_RHS.m12 + m32 * a_RHS.m13,
	m03 * a_RHS.m10 + m13 * a_RHS.m11 + m23 * a_RHS.m12 + m33 * a_RHS.m13,
	m00 * a_RHS.m20 + m10 * a_RHS.m12 + m20 * a_RHS.m22 + m30 * a_RHS.m23,
	m01 * a_RHS.m20 + m11 * a_RHS.m12 + m21 * a_RHS.m22 + m31 * a_RHS.m23,
	m02 * a_RHS.m20 + m12 * a_RHS.m12 + m22 * a_RHS.m22 + m32 * a_RHS.m23,
	m03 * a_RHS.m20 + m13 * a_RHS.m12 + m23 * a_RHS.m22 + m33 * a_RHS.m23,
	m00 * a_RHS.m30 + m10 * a_RHS.m13 + m20 * a_RHS.m23 + m30 * a_RHS.m33,
	m01 * a_RHS.m30 + m11 * a_RHS.m13 + m21 * a_RHS.m23 + m31 * a_RHS.m33,
	m02 * a_RHS.m30 + m12 * a_RHS.m13 + m22 * a_RHS.m23 + m32 * a_RHS.m33,
	m03 * a_RHS.m30 + m13 * a_RHS.m13 + m23 * a_RHS.m23 + m33 * a_RHS.m33);
}

Vector4 & Matrix4::operator[](int a_i)
{
	return m_V4Data[a_i];
}

Matrix4::operator float*()
{
	return data;
}

void Matrix4::setRotate(const float a_fRotation)
{
	setRotateZ(a_fRotation);
}

void Matrix4::setRotateX(const float a_fRotation)
{
	m00 = 1;
	m01 = 0;
	m02 = 0;
	m03 = 0;

	m10 = 0;
	m11 = cos(a_fRotation);
	m12 = sin(a_fRotation);
	m13 = 0;

	m20 = 0;
	m21 = -sin(a_fRotation);
	m22 = cos(a_fRotation);
	m23 = 0;

	m30 = 0;
	m31 = 0;
	m32 = 0;
	m33 = 1;
}

void Matrix4::setRotateY(const float a_fRotation)
{
	m00 = cos(a_fRotation);
	m01 = 0;
	m02 = -sin(a_fRotation);
	m03 = 0;

	m10 = 0;
	m11 = 1;
	m12 = 0;
	m13 = 0;

	m20 = sin(a_fRotation);
	m21 = 0;
	m22 = cos(a_fRotation);
	m23 = 0;

	m30 = 0;
	m31 = 0;
	m32 = 0;
	m33 = 1;
}

void Matrix4::setRotateZ(const float a_fRotation)
{
	m00 = cos(a_fRotation);
	m01 = sin(a_fRotation);
	m02 = 0;
	m03 = 0;

	m10 = -sin(a_fRotation);
	m11 = cos(a_fRotation);
	m12 = 0;
	m13 = 0;

	m20 = 0;
	m21 = 0;
	m22 = 1;
	m23 = 0;

	m30 = 0;
	m31 = 0;
	m32 = 0;
	m33 = 1;
}