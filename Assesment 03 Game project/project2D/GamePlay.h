#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Object.h"
#include "aabb.h"
#include "CircleColision.h"
#include <vector>
//#include "Circle.h"

class GamePlay : public aie::Application {
public:

	GamePlay();
	virtual ~GamePlay();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void DrawAABB(const aabb& a_AABB, aie::Renderer2D* a_Renderer);
	void DrawCircle(Vector3 center, float Radius, int segments, aie::Renderer2D* a_Renderer);

protected:

	//Colliders For Collision
	aabb				bulletCollider;
	aabb				SquareCollider;
	aabb				TankCollider;

	CircleColision		AsteroidCollider;
	//CircleColision		Collider;

	//aabb				bulletCollider2;
	//aabb				SquareCollider2;
	//aabb				TankCollider2;

	//Allready existing members from bootstrap
	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;
	
	float m_cameraX, m_cameraY;
	float m_timer;

	//Transform and Texture creation for Tank
	Matrix3			m_TankTransform;
	Matrix3			m_TankLocalTransform;
	aie::Texture*	m_TankTexture;

	//Matrix3			m_TankTransform2;
	//Matrix3			m_TanklocalTransform2;
	//aie::Texture*		m_TankTexture2;

	//Transform and Texture creation for Cannon 
	Matrix3			m_CannonTransform;
	Matrix3			m_CannonLocalTransform;
	aie::Texture*	m_CannonTexture;

	//Matrix3			m_CannonTransform2;
	//Matrix3			m_CannonLocalTransform2;
	//aie::Texture*		m_CannonTexture2;

	//Asteroid constructores
	Object*			m_Asteroid;
	Matrix3			m_AsteroidTransform;
	Matrix3			m_AsteroidLocalTransform;
	aie::Texture*	m_AsteroidTexture;
	float			m_AsteroidSpeed;
	float			m_AsteroidRotationSpeed;

	//Small Asteroid Constructores
	Object*			m_SmallAsteroid;
	Matrix3			m_SmallAsteroidTransform;
	Matrix3			m_SmallAsteroidLocalTransform;
	aie::Texture*	m_SmallAsteroidTexture;
	float			m_SmallAsteroidSpeed;

	//Tank constructores
	Object*			m_Tank;
	//Object*			m_Tank2;
	float			m_TankSpeed;
	float			m_TankRotation;
	float			m_TankRotationSpeed;
	
	//Cannon Constructores
	Object*			m_Cannon;
	//Object*			m_Cannon2;
	float			m_CannonRotation;
	float			m_CannonRotationSpeed;
	
	//Bullet cunstructores
	Matrix3			m_BulletTransform;
	aie::Texture*	m_BulletTexture;
	float			m_BulletVelocity;
	float			m_Bulletspeed;
	float			m_BulletRotation;

	//Conditionals for fireing the cannon and float for movment
	float			m_accelerationSpeed;
	bool			m_FireCannon;
	
	//Conditionals for collision
	bool			IsCollided;
	bool			TankCollided;
	bool			CubeCollided;
	bool			CircleCollided;
	bool			ADestroyCollided;
	bool			TDestroyCollided;

	//for spawning new smaller astroid
	bool			m_bSpawnOnce = true;
	bool			m_bIsActive = false;
	bool			m_IsBulletActive = false;
	bool			m_ActiveCollider = true;
	bool			m_smallAsteroidAlive = true;
	bool			m_smallAsteroiedDead = false;

	float			m_fTimer;


	Vector3			CenterPos;
	Vector3			Direction;
	std::vector<Object*> Asteroids;
	std::vector<int> AsteroidID;
	std::vector<int> ColliderID;

};