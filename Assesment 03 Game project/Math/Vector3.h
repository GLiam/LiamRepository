#pragma once
class Vector3
{
public:

	union
	{
		struct 
		{
			float x;
			float y;
			float z;
		};
		float data[3];
		
	};

	Vector3();
	Vector3(const float a_FX, const float a_FY, const float a_FZ);
	//Vector3(const Vector3& other) = default;
	//Vector3& operator=(const Vector3& other) = default;

	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	Vector3 operator*(const float& a_RHS) const;
	Vector3 operator/(const float& a_RHS) const;

	float dot(Vector3 V3);

	void Scale(const float& a_fScale);
	void Translate(const Vector3& a_v3Translation);

	float magnitude();
	float SqrMagnitude();
	float normalise();

	Vector3 cross(const Vector3 & a_V1) const;

	float& operator[](int a_i);
	explicit operator float*();

	//void Add(const Vector3& other);
	//void Subtract(const Vector3& other);
	//void ScaleMultiply(float other);
	//void ScaleDevide(float other);
	//float GetMagnitude() const;
	//Vector3 GetNormalised() const;
	//void Normalise();
//	float x;
//	float y;
//	float z;
};

static Vector3 operator*(const float a_fScale, const Vector3& a_RHS)
{
	return a_RHS * a_fScale;
}