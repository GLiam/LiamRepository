#pragma once
#include "Vector2.h"
class aabb
{
public:

	union
	{
		struct
		{
			Vector2 v2Position;
			Vector2 v2Extents;
		};
		struct 
		{
			float x, y, halfWidth, halfHight;
		};
	};


	aabb();
	aabb(const Vector2& a_v2Position, const Vector2& a_v2Extents);
	aabb(const float a_fPosx, const float a_fPosy, const float a_fHalfX, const float a_fHalfY);

	static bool CollisionCheck(const aabb& a_AABB, const Vector2& a_v2Point);
	static bool CollisionCheck(const aabb& a_AABB_LHS, const aabb& a_AABB_RHS);

	bool CollidesWith(const Vector2& a_v2Piont) const;
	bool CollidesWith(const aabb& a_AABB_RHS) const;
};