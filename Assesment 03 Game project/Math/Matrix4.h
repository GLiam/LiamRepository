#pragma once
#include "Vector4.h"

class Matrix4
{
public:

	union
	{
		struct
		{
			float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;
		};
		float data[12];
		struct
		{
			Vector4 m_V4Data[4];
		};
	};


	Matrix4();
	Matrix4(const float a_m00, const float a_m01, const float a_m02, const float a_m03,
			const float a_m10, const float a_m11, const float a_m12, const float a_m13,
			const float a_m20, const float a_m21, const float a_m22, const float a_m23,
			const float a_m30, const float a_m31, const float a_m32, const float a_m33);

	Vector4 operator*(const Vector4& a_RHS);
	Matrix4 operator*(const Matrix4& a_RHS);

	Vector4& operator[](int a_i);

	explicit operator float*();

	
	void setRotate(const float a_fRotation);
	void setRotateX(const float a_fRotation);
	void setRotateY(const float a_fRotation);
	void setRotateZ(const float a_fRotation);
	void setRotateW(const float a_fRotation);


};

