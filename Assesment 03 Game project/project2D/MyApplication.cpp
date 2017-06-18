#include "MyApplication.h"
#include "GameStateManager.h"


MyApplication::MyApplication()
{
}


MyApplication::~MyApplication()
{
}

bool MyApplication::startup()
{
	GS_Manager = new GameStateManager();
	GS_Manager->startup();
	return true;
}

void MyApplication::shutdown()
{
	GS_Manager->shutdown();
	//delete GS_Manager;
}

void MyApplication::update(float deltaTime)
{
	GS_Manager->update(deltaTime);
}

void MyApplication::draw()
{
	GS_Manager->draw();
}
