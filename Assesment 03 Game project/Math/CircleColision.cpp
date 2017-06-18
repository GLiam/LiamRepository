#include "CircleColision.h"
#include <iostream>
#include <cmath>
#include "Circle.h"
#include "Vector3.h"


CircleColision::CircleColision()
{
}

CircleColision::CircleColision(const Vector3 & a_cPosition, const float a_cRadius)
{
	cPosition = a_cPosition;
	cRadius = a_cRadius;
}

CircleColision::CircleColision(const float a_fPosX, const float a_fPosY, const float a_Radius)
{
	cPosition = Vector3(a_fPosX, a_fPosY, 0);
	cRadius = a_Radius;
}

bool CircleColision::IsPointInCircle(float xa, float ya, float xc, float yc, float r)
{
	return ((xa - xc)*(xa - xc) + (ya - yc)*(ya - yc)) < r*r;
}
							//square			//circle	
bool CircleColision::cAABB( Vector3 V_a, float a_HalfX,  Vector3 V_b, float a_HalfY, float fR)
{
	float distance;

	//get distance between circle a square
	
	//vectorA - vectorB = distance
	Vector3 tempDistance;
	tempDistance = V_a - V_b;
	distance = tempDistance.magnitude();
	if (distance < fR)
	{
		Vector3 V_X;
		Vector3 V_Y;
		V_X.x = 1;
		V_Y.y = 1;


		V_a.dot(V_X) * 1280;
		V_b.dot(V_Y) * 720;

		a_HalfX = 1280 / 2;
		a_HalfY = 720 / 2;

		float fX;
		float fY;

		fX = tempDistance.dot(V_X) * 1280;
		fY = tempDistance.dot(V_Y) * 720;

		float Pc;

		Pc = fR + (fX, fY);
		
		if (Pc < fR)
		{
			return true;
		}

	}
	//dot producte betwwen world X and vector
	// "     "               "   Y  "       "
		//get halfWidth and halfHight of object 
		//distance cheack between circle and square 
		// if it's less than the rediuse of the circle = collision
	return false;
}

bool CircleColision::CircleCheck(CircleColision a_LH, CircleColision a_RH)
{
	Vector3 V1 = a_LH.cPosition;
	Vector3 V2 = a_RH.cPosition;
	Vector3 temp = V1 - V2;
	const float RadiusLen = (a_LH.cRadius + a_RH.cRadius);
	const float VectorLen = temp.magnitude();
	return RadiusLen > VectorLen;
}