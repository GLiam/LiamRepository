#pragma once
#include "Application.h"

class GameStateManager;

class MyApplication : public aie::Application
{
public:
	MyApplication();
	~MyApplication();

	bool startup();
	void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	GameStateManager* GS_Manager;

};

