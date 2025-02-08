#include "../../header/GamePlay/GameplayService.h"
//#include "../../header/GamePlay/GameplayController.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}

	GameplayService::~GameplayService()
	{
		destroy();
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
	}

	void GameplayService::startGame()
	{
		gameplay_controller->restart();
	}


	void GameplayService::endGame(GameResult result)
	{
		gameplay_controller->endGame(result);
	}

	void GameplayService::destroy()
	{
		delete(gameplay_controller);
	}

	float GameplayService::getRemainingTime()
	{
		return gameplay_controller->getRemainingTime();
	}

	int GameplayService::getMinesCount()
	{
		return gameplay_controller->getMinesCount();
	}
}