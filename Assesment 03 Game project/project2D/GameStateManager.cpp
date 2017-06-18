#include "GameStateManager.h"
#include "MenuManager.h"
#include "GamePlay.h"

GameStateManager::GameStateManager()
{
	MenuPage = new MenuManager();
	Gameplay = new GamePlay();
}


GameStateManager::~GameStateManager()
{
	delete MenuPage;
	Gameplay->shutdown();
	delete Gameplay;
}

bool GameStateManager::startup()
{
	Gameplay->startup();
	return true;
}

bool GameStateManager::shutdown()
{
	Gameplay->shutdown();
	return true;
}

void GameStateManager::update(float deltatime)
{
	switch(currentState)
	{
	case Estates::Menu:
		MenuPage->update();
		break;
	case Estates::Game:
		Gameplay->update(deltatime);
		break;
	default:
		break;
	}
}

void GameStateManager::draw()
{
	switch (currentState)
	{
	case Estates::Menu:
		MenuPage->draw();
		break;
	case Estates::Game:
		Gameplay->draw();
		break;
	default:
		break;
	}
}
