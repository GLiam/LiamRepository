#include "GamePlay.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>
#include <cmath>
#include "Application.h"

GamePlay::GamePlay() {

}

GamePlay::~GamePlay() {

}

bool GamePlay::startup() {

	m_2dRenderer = new aie::Renderer2D();
	
	float HalfHight = 640;/*getWindowHeight() / 2;*/
	float HalfWidth = 720;/*getWindowWidth() / 2;*/

	CenterPos = Vector3(HalfWidth, HalfHight, 0);
	
	//m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_TankTexture = new aie::Texture("./textures/tankBlue.png");
	m_CannonTexture = new aie::Texture("./textures/barrelBlue.png");
//	m_TankTexture2 = new aie::Texture("./textures/tankGreen.png");
//	m_CannonTexture2 = new aie::Texture("./textures/barrelGreen.png");
	m_BulletTexture = new aie::Texture("./textures/bullet.png");
	m_AsteroidTexture = new aie::Texture("./textures/rock_Medium.png");
	m_SmallAsteroidTexture = new aie::Texture("./textures/rock_Small.png");

	m_TankTransform[2] = Vector3(600, 600, 1);
	m_CannonTransform[2] = Vector3(600, 630, 1);
//	m_AsteroidTransform[2] = Vector3(PosX, PosY, 0.0f);
	m_SmallAsteroidTransform[2] = Vector3(m_AsteroidTransform.position.x, m_AsteroidTransform.position.y, 0.0f);

//	std::cout << PosX << " " << PosY << std::endl;

//	m_TankTransform2[2] = Vector3(600, 300, 1);
//	m_CannonTransform2[2] = Vector3(600, 330, 1);

	for(unsigned int i = 0; i < 5; i++)
	{
		int PosX = (rand() % 1280);
		int PosY = (rand() % 720) + 720;
		
		Vector3 Position(PosX, PosY, 0.0f);
		m_Asteroid = new Object(Position, CenterPos - Position, m_AsteroidTexture);
		Asteroids.push_back(m_Asteroid);
		AsteroidID.push_back(i + 1);
	}

	for(int i = 0; i < Asteroids.size(); i++)
	{
		AsteroidCollider = CircleColision(m_AsteroidTransform.position.x, m_AsteroidTransform.position.y, 0.0f);
		AsteroidCollider.cRadius = m_AsteroidTexture->getWidth();
		
		Asteroids.erase(Asteroids.begin() + i);

		ColliderID.push_back(i + 1);
	}

	Vector3 Zero;
	Direction = CenterPos - m_AsteroidTransform.position;
	
	SquareCollider = aabb(300, 300, 200, 200);
	TankCollider = aabb(75, 75, 37, 37);

	m_AsteroidSpeed = 0.1f;
	m_AsteroidRotationSpeed = 3;

	m_TankSpeed = 3;
	m_TankRotation = 0;
	m_TankRotationSpeed = 1.5;

	m_CannonRotation = 0;
	m_CannonRotationSpeed = 1.5;

	//m_FireCannon = false;
	m_Bulletspeed = 0;
	m_accelerationSpeed = 6;
	m_BulletRotation = 0;

	IsCollided = false;
	TankCollided = false;
	CubeCollided = false;
	CircleCollided = false;
	ADestroyCollided = false;

	m_fTimer = 0.0f;

	m_font = new aie::Font("./font/consolas.ttf", 32);
//	m_audio = new aie::Audio("./audio/powerup.wav");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;

}

void GamePlay::shutdown() {
	
	//delete m_audio;
	delete m_font;
	//delete m_texture;
	delete m_TankTexture;
	delete m_CannonTexture;
	delete m_SmallAsteroidTexture;
	//delete m_AsteroidTexture;
	delete m_BulletTexture;
	delete m_2dRenderer;
	//delete m_Asteroid;
	for (unsigned int i = 0; i < Asteroids.size(); ++i)
	{
		delete Asteroids.at(i);
		Asteroids.at(i) = nullptr;
	}

}

void GamePlay::update(float deltaTime) {

	m_timer += deltaTime;

	//box1.x = m_TankTransform.position.x;
	//box1.y = m_TankTransform.position.y;

	//sets bullets collider to it's position
	bulletCollider.v2Position.x = m_BulletTransform.position.x;
	bulletCollider.v2Position.y = m_BulletTransform.position.y;

	//
	TankCollider.x = m_TankTransform.position.x;
	TankCollider.y = m_TankTransform.position.y;

	Vector3 Oriantion = CenterPos - m_AsteroidTransform.position;

	//Asteroids direction and movement whiles spawns off screen
	m_AsteroidTransform.position =						//Direction  = Center of the screen - Astroids position
		m_AsteroidTransform.position + (Direction * (m_AsteroidSpeed * /*m_AsteroidTransform.forward */ deltaTime));

	AsteroidCollider.cPosition =
		AsteroidCollider.cPosition + (Direction * (m_AsteroidSpeed * /*m_AsteroidTransform.forward */ deltaTime));
	//////

	for(int i = 0; i < Asteroids.size(); i++)
	{
		Asteroids[i]->Update(deltaTime);
	}

	// input example
	aie::Input* input = aie::Input::getInstance();
	// W,A,S,D to move tank up forward and back and rotate it to the left and right
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		m_TankTransform.position =
			m_TankTransform.position + m_TankSpeed * m_TankTransform.forward;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		m_TankTransform.position =
			m_TankTransform.position - m_TankSpeed * m_TankTransform.forward;
	}

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		Matrix3 rot;
		rot.setRotateZ(m_TankRotationSpeed * -deltaTime);
		m_TankTransform = m_TankTransform * rot;

	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		Matrix3 rot;
		rot.setRotateZ(m_TankRotationSpeed * deltaTime);
		m_TankTransform = m_TankTransform * rot;
	}
	//////

	// use arrow keys to move cannon
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		Matrix3 rot;
		rot.setRotateZ(m_CannonRotationSpeed * deltaTime);
		m_CannonLocalTransform = rot * m_CannonLocalTransform;
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		Matrix3 rot;
		rot.setRotateZ(m_CannonRotationSpeed * -deltaTime);
		m_CannonLocalTransform = rot * m_CannonLocalTransform;
	}

	////	if(input->isKeyDown(aie::INPUT_KEY_UP))
		//{
		//	m_TankTransform2.position =
		//		m_TankTransform2.position + m_TankSpeed * m_TankTransform2.forward;
		//}
	////	if(input->isKeyDown(aie::INPUT_KEY_DOWN))
		//{
		//	m_TankTransform2.position =
		//		m_TankTransform2.position - m_TankSpeed * m_TankTransform2.forward;
		//}
	////
	////	if(input->isKeyDown(aie::INPUT_KEY_RIGHT))
		//{
		//	Matrix3 rot;
		//	rot.setRotateZ(m_TankRotationSpeed * -deltaTime);
		//	m_TankTransform2 = m_TankTransform2 * rot;
	  //
		//}
	////	if(input->isKeyDown(aie::INPUT_KEY_LEFT))
		//{
		//	Matrix3 rot;
		//	rot.setRotateZ(m_TankRotationSpeed * deltaTime);
		//	m_TankTransform2 = m_TankTransform2 * rot;
		//}
	////
	////
	////	if(input->isKeyDown(aie::INPUT_KEY_1))
		//{
		//	Matrix3 rot;
		//	rot.setRotateZ(m_CannonRotationSpeed * deltaTime);
		//	m_CannonLocalTransform2 = rot * m_CannonLocalTransform2;
		//}
	////	if(input->isKeyDown(aie::INPUT_KEY_0))
		//{
		//	Matrix3 rot;
		//	rot.setRotateZ(m_CannonRotationSpeed * -deltaTime);
		//	m_CannonLocalTransform2 = rot * m_CannonLocalTransform2;
		//}

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE) && m_IsBulletActive == false)
	{
		Matrix3 rot;
		//m_FireCannon = true;
		m_BulletTransform = m_CannonTransform;
	/*	m_BulletTransform.position =
			m_CannonTransform.position + m_CannonTransform.forward * m_CannonTexture->getHeight();*/

		m_IsBulletActive = true;
		//rot.setRotate(m_CannonRotation);

		if (IsCollided == true)
		{
			// -> collision has happened
			m_smallAsteroiedDead = true;
		}
	}

	if (m_IsBulletActive)
	{
		//bullets movement is set when cannon is fired
		m_BulletTransform.position =
			m_BulletTransform.position + m_accelerationSpeed * m_BulletTransform.forward;
	}
	//if our astroid is destroyed then collisions will occur 
	if (m_ActiveCollider)//fix player vs dead astroid collision
	{
		//checks circle to Axis alighned bounding box collision
		//"Asteroid to Tank"
		if (CircleColision::cAABB(AsteroidCollider.cPosition, AsteroidCollider.cRadius, Vector3(TankCollider.v2Position.x, TankCollider.v2Position.y, 0), TankCollider.halfHight, AsteroidCollider.cRadius))
		{
			TDestroyCollided = true;
		}
	}
	//"Asteroid to Bullet"
	if (CircleColision::cAABB(AsteroidCollider.cPosition, AsteroidCollider.cRadius, Vector3(bulletCollider.x, bulletCollider.y, 0), bulletCollider.halfHight, AsteroidCollider.cRadius))
	{

		// bullet just collided with asteroid
		ADestroyCollided = true;
		m_IsBulletActive = false;
		m_BulletTransform.position = m_CannonTransform.position;
		//debug
		std::cout << "Bullet Collision with Asteroid" << std::endl;

		if(m_smallAsteroiedDead == true)
		{
			m_smallAsteroidAlive = false;
		}
	}



	//Tank Screen wraping
	if(m_TankTransform.position.x > 1280)
	{
		m_TankTransform.position.x = 0;
	}
	if(m_TankTransform.position.x < 0)
	{
		m_TankTransform.position.x = 1280;
	}
	if(m_TankTransform.position.y > 720)
	{
		m_TankTransform.position.y = 0;
	}
	if(m_TankTransform.position.y < 0)
	{
		m_TankTransform.position.y = 720;
	}
	////////


	///Asteroid Screen wraping
	//if(m_AsteroidTransform.position.x > 1280 && AsteroidCollider.cPosition.x > 1280)
	//{
	//	m_AsteroidTransform.position.x = 0;
	//	AsteroidCollider.cPosition.x = 0;
	//}
	//if(m_AsteroidTransform.position.x < 0 && AsteroidCollider.cPosition.x < 0)
	//{
	//	m_AsteroidTransform.position.x = 1280;
	//	AsteroidCollider.cPosition.x = 1280;
	//}
	//if(m_AsteroidTransform.position.y > 720 && AsteroidCollider.cPosition.y > 720)
	//{
	//	m_AsteroidTransform.position.y = 0;
	//	AsteroidCollider.cPosition.y = 0;
	//}
	//if(m_AsteroidTransform.position.y < 0 && AsteroidCollider.cPosition.y < 0)
	//{
	//	m_AsteroidTransform.position.y = 720;
	//	AsteroidCollider.cPosition.y = 720;
	//}

	//delets bullet when it goes of screen
	if(m_BulletTransform.position.x > 1280)
	{
		m_IsBulletActive = false;
	}
	else if(m_BulletTransform.position.x < 0)
	{
		m_IsBulletActive = false;
	}
	else if(m_BulletTransform.position.y > 720)
	{
		m_IsBulletActive = false;
	}
	else if(m_BulletTransform.position.y < 0)
	{
		m_IsBulletActive = false;
	}
	////////

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	//m_Tank->Update(deltaTime);
	//Matrix3 rot;
	//rot.setRotateZ(m_CannonRotationSpeed * deltaTime);
	//m_CannonLocalTransfrom = rot * m_CannonLocalTransfrom;
	//rot.setRotateZ(m_TankRotationSpeed * -0.5 * deltaTime);
	//m_TankTransform = m_TankTransform * rot;
	
	int(m_fTimer += deltaTime);

	//cannons position is set to the tanks
	m_CannonTransform = m_TankTransform * m_CannonLocalTransform;
//	m_CannonTransform2 = m_TankTransform2 * m_CannonLocalTransform2;

}

void GamePlay::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->drawSpriteTransformed3x3(m_TankTexture, (float*)m_TankTransform);
	m_2dRenderer->drawSpriteTransformed3x3(m_CannonTexture, (float*)m_CannonTransform, 0, 0, 0, 0.5, 0);

	//m_2dRenderer->drawSpriteTransformed3x3(m_AsteroidTexture, (float*)m_AsteroidTransform);

	//if big asteroid is destroyed
	if (ADestroyCollided == true)
	{
		////if small asteroid is not active
		//if (m_bIsActive)
		//{
		//	//disable bullet drawing.
		//	m_IsBulletActive = false;
		//}
		//else
		//{
		//	m_IsBulletActive = true;
		//}
		// start rendering the smaller astroid

		if (m_smallAsteroidAlive == true)
		{
			m_2dRenderer->drawSpriteTransformed3x3(m_SmallAsteroidTexture, (float*)m_AsteroidTransform);
		}
		//disable draw for big asteroid
		IsCollided = true;

		//disable collider for big asteroid
		m_ActiveCollider = false;
	}


	//if(m_FireCannon == true )
	//{
		//bullets collider get created when the cannon is fired
	bulletCollider = aabb(2, 2, 1, 1);
	if(m_IsBulletActive == true)
	{
		//Draws the bullet when the bullet is active 
		m_2dRenderer->drawSpriteTransformed3x3(m_BulletTexture, (float*)m_BulletTransform, 0, 0, 0, 1, 1);


	}
	//}

	for (int i = 0; i < Asteroids.size(); i++)
	{
		Asteroids[i]->Draw(m_2dRenderer);		
	}

	if(IsCollided == false)
	{
		//draws asteroid as long as theres no collision
		m_2dRenderer->drawSpriteTransformed3x3(m_AsteroidTexture, (float*)m_AsteroidTransform);
		//m_2dRenderer->setRenderColour(0, 1, 1, 1);
		
		//creates asteroids collider as long as theres no collision 

		///colliders will stay true or false until ->
		//m_smallAsteroidAlive = true;
		//m_smallAsteroiedDead = false;
	}
	
	// cheacks if the tank has been hit by an Asteroid
	// and if it has the game will end
	if(TDestroyCollided == true)
	{
		//draws text telling you, you lost 
		m_2dRenderer->drawText(m_font, "YOU SUCK AT GAMES", 640, 360, 2);
		//tank hit debug
		std::cout << "TANKS FOR THE MEMORIES EVEN THOUGH THEY WERNT SO GREAT" << std::endl;
		//tanks collider is made false
		TDestroyCollided = false;

	}

	//draws tank controls for player
	m_2dRenderer->drawText(m_font, "W to move forwards, S to move backwards", 2, 38, 2);
	m_2dRenderer->drawText(m_font, "A to Rotate left, D to Rotate right", 1, 10, 1);
	
	//creats and draws the time to screen "writen by Adam"
	char* c = new char[4]{ 0 };
	itoa(int(m_fTimer), c, 10);
	int length = strlen(c);
	
	switch (length)
	{
	case 1:
		c[2] = c[0];
		c[0] = '0';
		c[1] = '0';
		break;

	case 2:
		c[2] = c[1];
		c[1] = c[0];
		c[0] = '0';
		break;
	default:
		break;
	}
	//
	m_2dRenderer->drawText(m_font, c, 573, 690);

//	DrawAABB(bulletCollider, m_2dRenderer);
//	DrawAABB(SquareCollider, m_2dRenderer);
//	DrawAABB(TankCollider, m_2dRenderer);
//	DrawCircle(Vector3(m_AsteroidTransform.position.x, m_AsteroidTransform.position.y, 0.0f), AsteroidCollider.cRadius, 25, m_2dRenderer);
//	DrawCircle(Vector3(AsteroidCollider.cPosition.x, AsteroidCollider.cPosition.y, 0.0f), AsteroidCollider.cRadius, 25, m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();

}

//for drawing the axis alighened bounding box to screen
void GamePlay::DrawAABB(const aabb & a_AABB, aie::Renderer2D * a_Renderer)
{
	a_Renderer->drawLine(a_AABB.x - a_AABB.halfWidth, a_AABB.y - a_AABB.halfHight,
		a_AABB.x - a_AABB.halfWidth, a_AABB.y + a_AABB.halfHight);

	a_Renderer->drawLine(a_AABB.x - a_AABB.halfWidth, a_AABB.y + a_AABB.halfHight,
		a_AABB.x + a_AABB.halfWidth, a_AABB.y + a_AABB.halfHight);

	a_Renderer->drawLine(a_AABB.x + a_AABB.halfWidth, a_AABB.y + a_AABB.halfHight,
		a_AABB.x + a_AABB.halfWidth, a_AABB.y - a_AABB.halfHight);

	a_Renderer->drawLine(a_AABB.x + a_AABB.halfWidth, a_AABB.y - a_AABB.halfHight,
		a_AABB.x - a_AABB.halfWidth, a_AABB.y - a_AABB.halfHight);

}

//for drawing the circles to screen
void GamePlay::DrawCircle(Vector3 center, float Radius, int segments, aie::Renderer2D * a_Renderer)
{
	//float angle = 0;
	float anglePerLine = (3.1415f * 2) / segments;
	float angle = 0;
	while (angle <= 3.1415f)
	{
		float nextAngle = angle + anglePerLine;

		Vector3 currentPoint;
		currentPoint.x = center.x + (cos(angle) * Radius);
		currentPoint.y = center.y + (sin(angle) * Radius);

		Vector3 nextPoint;
		nextPoint.x = center.x + (cos(nextAngle) * Radius);
		nextPoint.y = center.y + (sin(nextAngle) * Radius);
		
		a_Renderer->drawLine(currentPoint.x, currentPoint.y,
			nextPoint.x, nextPoint.y, 1.0f, center.z);
		//		Vector3 nextPoint;

		currentPoint.x = center.x + (cos(angle) * Radius);
		currentPoint.y = center.y - (sin(angle) * Radius);

		nextPoint.x = center.x + (cos(nextAngle) * Radius);
		nextPoint.y = center.y - (sin(nextAngle) * Radius);

		a_Renderer->drawLine(currentPoint.x, currentPoint.y,
			nextPoint.x, nextPoint.y, 1.0f, center.z);

		angle = nextAngle;
	}

}