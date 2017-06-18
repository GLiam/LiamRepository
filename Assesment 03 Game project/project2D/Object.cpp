#include "Object.h"
#include "CircleColision.h"

Object::Object(const Vector3 & a_pos, Vector3 Direction, aie::Texture * const a_Texture)
{
	m_LocalTransform = new Matrix3();
	//m_v3Direction = m_LocalTransform->forward;
	m_v3Direction = Direction;
	m_v3Direction.normalise();
	//m_fDirection = (*m_LocalTransform)[1];
	m_LocalTransform->position = a_pos;
	//(*m_LocalTransform)[2] = a_pos;
	m_ObjTexture = a_Texture;

	m_fSpeed = 100.0f;

	m_GlobalTransform = new Matrix3(*m_LocalTransform);

	m_Children = new std::vector<Object*>();
}

void Object::Update(const float a_fDeltaTime)
{
	if (m_Parent)
	{
		*m_GlobalTransform = *m_Parent->m_GlobalTransform * *m_LocalTransform;
		m_GlobalTransform->position = m_GlobalTransform->position + (m_v3Velocity * a_fDeltaTime);
		m_LocalTransform->position = m_Parent->m_GlobalTransform->position - m_GlobalTransform->position;
	}
	else
	{

		m_LocalTransform->position = m_LocalTransform->position + (m_v3Direction * m_fSpeed * a_fDeltaTime);
		*m_GlobalTransform = *m_LocalTransform;
	}
	
	for (int i = 0; i < m_Children->size(); ++i)
	{
		m_Children->at(i)->Update(a_fDeltaTime);
	}

}

void Object::Draw(aie::Renderer2D * a_Render)
{
	a_Render->drawSpriteTransformed3x3(m_ObjTexture, (float*)m_GlobalTransform);
	

}

void Object::setSpeed(const float a_fSpeed)
{
	m_v3Velocity = a_fSpeed * m_GlobalTransform->forward;
}

void Object::setRotation(const float a_fRotation)
{
	m_LocalTransform->setRotateZ(a_fRotation);
	//m_v3Velocity = m_fSpeed * m_LocalTransform->forward;
}

void Object::setParent(Object * a_Parent)
{
	if (a_Parent)
	{
		if (m_Parent)
		{
			//m_Parent->m_Children->erase();
		}
		m_Parent = a_Parent;

		m_LocalTransform->position = m_Parent->m_GlobalTransform->position - m_LocalTransform->position;
		m_LocalTransform->position.z = 1;

		m_Parent->m_Children->push_back(this);
	}
	
}

Object::~Object()
{
	delete m_LocalTransform;
	delete m_GlobalTransform;
}