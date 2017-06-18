#pragma once
class Vector2
{
public:
	union
	{
		struct
		{
			float x;
			float y;
		};
		float data[2];
	};

	Vector2();
	//Vector2(const float x, const float y);
	Vector2(float a_FX, float a_FY);
	//Vector2& operator=(const Vector2& other) = default;


	// oerator functions 
	Vector2 operator+(const Vector2& a_RHS) const;
	Vector2 operator-(const Vector2& a_RHS) const;
	Vector2 operator*(const float& a_RHS) const;
	Vector2 operator/(const float& a_RHS) const;


	// dot product
	float dot(Vector2 V2);

	// scaler multiply + translate functions
	void Scale(const float& a_fScale);
	void Translate(const Vector2& a_v2Translation);


	// magnitude sre magnitude and normalise functions
	float magnitude();
	float SqrMagnitude();
	float normalise();

	// square operator function
	float& operator[](int a_i);
	explicit operator float*();
};

static Vector2 operator*(const float a_fScale, const Vector2& a_RHS)
{
	return a_RHS * a_fScale;
}