#pragma once
#include "Circle.h"

class CircleColision
{
public:
public:
	union
	{
		struct
		{
			Vector3 cPosition;
			float cRadius;
		};
	};

	CircleColision();
	CircleColision(const Vector3& a_cPosition, const float a_cRadius);
	CircleColision(const float a_fPosX, const float a_fPosY, const float a_Radius);

	bool IsPointInCircle(float xa, float ya, float xc, float yc, float r);

	static bool cAABB( Vector3 V_a, const float a_HalfX,  Vector3 V_b, const float a_HalfY, float fR);

	static bool CircleCheck(CircleColision a_LH, CircleColision a_RH);
};