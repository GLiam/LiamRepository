#pragma once
#include "Vector3.h"

class Collider
{
public:
	union
	{
		struct
		{
			Vector3 cPosition;
			float cRadius;
		};
	};

	Collider();
};