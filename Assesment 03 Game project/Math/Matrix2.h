#pragma once
#include "Vector2.h"

class Matrix2
{
public:

	union 
	{
		struct 
		{
			float m00, m01, m10, m11;
		};
		float data[4];
		struct
		{
			Vector2 m_V2Data[2];
		};
	};


	Matrix2();
	Matrix2(const float a_m00, const float a_m01,
			const float a_m10, const float a_m11);

	Vector2 operator*(const Vector2& a_RHS);
	Matrix2 operator*(const Matrix2& a_RHS);

	Vector2& operator[](int a_i);

	explicit operator float*();

	void setRotate(const float a_fRotation);

	//void setRotation(float a_AngleRadians);
	//void setRotationDeg(float a_AngleRadians);

};

