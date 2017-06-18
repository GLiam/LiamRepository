#pragma once
class Vector4
{
public:

	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		float data[3];
	};

	Vector4();
	Vector4(const float a_FX, const float a_FY, const float a_FZ, const float a_FW);


	Vector4 operator+(const Vector4& a_RHS) const;
	Vector4 operator-(const Vector4& a_RHS) const;
	Vector4 operator*(const float & a_RHS) const;
	Vector4 operator/(const float & a_RHS) const;

	float dot(Vector4 V4);

	void Scale(const float& a_fScale);
	void Translate(const Vector4& a_v4Translation);

	float magnitude();
	float SqrMagnitude();
	float normalise();

	Vector4 cross(const Vector4& a_V1) const;
	
	float& operator[](int a_i);
	explicit operator float*();

};

static Vector4 operator*(const float a_fScale, const Vector4& a_RHS)
{
	return a_RHS * a_fScale;
}

