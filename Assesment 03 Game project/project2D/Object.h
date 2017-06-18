#pragma once
#include <vector>
#include "Texture.h"
#include "Matrix3.h"
#include "Renderer2D.h"

class Object
{
public:
	Object(const Vector3& a_pos, Vector3 Direction, aie::Texture* const a_Texture);
	virtual ~Object(); //= 0 {};

	virtual void Update(const float a_fDeltaTime);
	void Draw(aie::Renderer2D* a_Render);
	void setSpeed(const float a_fSpeed);
	void setRotation(const float a_frotation);

	void setParent(Object* a_Parent);

protected:
	aie::Texture* m_ObjTexture			= nullptr;
	float m_fSpeed						= 0.0f;


private:
	Object* m_Parent					= nullptr;
	std::vector<Object*>* m_Children	= nullptr;

	Matrix3* m_GlobalTransform			= nullptr;
	Matrix3* m_LocalTransform			= nullptr;

	Vector3 m_v3Direction				= Vector3(0.0f, 0.0f, 0.0f);
	Vector3 m_v3Velocity				= Vector3(0.0f, 0.0f, 0.0f);


};