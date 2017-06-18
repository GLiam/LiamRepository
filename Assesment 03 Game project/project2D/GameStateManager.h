#pragma once
class MenuManager;
class GamePlay;

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();

	bool startup();
	bool shutdown();

	void update(float deltatime);
	void draw();

	enum Estates
	{
		Menu,
		Game
	};

protected:
	Estates currentState = Estates::Game;
	MenuManager* MenuPage;
	GamePlay* Gameplay;
};

