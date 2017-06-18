#include "aabb.h"

aabb::aabb()
{
}

aabb::aabb(const Vector2 & a_v2Position, const Vector2 & a_v2Extents)
{
	v2Position = a_v2Position;
	v2Extents = a_v2Extents;
}

aabb::aabb(const float a_fPosx, const float a_fPosy, const float a_fHalfX, const float a_fHalfY)
{
	v2Position = Vector2(a_fPosx, a_fPosy);
	v2Extents = Vector2(a_fHalfX, a_fHalfY);
}

bool aabb::CollisionCheck(const aabb & a_AABB, const Vector2 & a_v2Point) 
{
	return
	  !((a_AABB.x + a_AABB.halfWidth < a_v2Point.x) ||
		(a_AABB.y + a_AABB.halfHight < a_v2Point.y) ||
		(a_AABB.x - a_AABB.halfWidth > a_v2Point.x) ||
		(a_AABB.y - a_AABB.halfHight > a_v2Point.y));
}

bool aabb::CollisionCheck(const aabb & a_AABB_LHS, const aabb & a_AABB_RHS) 
{
	return
	  !((a_AABB_LHS.x + a_AABB_LHS.halfWidth < a_AABB_RHS.x - a_AABB_RHS.halfWidth) ||
		(a_AABB_LHS.y + a_AABB_LHS.halfHight < a_AABB_RHS.y - a_AABB_RHS.halfHight) ||
		(a_AABB_LHS.x - a_AABB_LHS.halfWidth > a_AABB_RHS.x + a_AABB_RHS.halfWidth) ||
		(a_AABB_LHS.y - a_AABB_LHS.halfHight > a_AABB_RHS.y + a_AABB_RHS.halfHight));
}

bool aabb::CollidesWith(const Vector2 & a_v2Piont) const 
{ 
	return CollisionCheck(*this, a_v2Piont);
}

bool aabb::CollidesWith(const aabb & a_AABB_RHS) const 
{
	return CollisionCheck(*this, a_AABB_RHS);
}
