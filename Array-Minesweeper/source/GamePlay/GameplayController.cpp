#include "../../header/GamePlay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;

	GameplayController::GameplayController()
	{

	}

	GameplayController::~GameplayController()
	{
		board_service = nullptr;
	}

	void GameplayController::initialize()
	{
		board_service = ServiceLocator::getInstance()->getBoardService();
	}

	void GameplayController::update()
	{
		updateRemainingTime();
	}

	void GameplayController::render()
	{

	}

	void GameplayController::restart()
	{
		remaining_time = max_duration;
	}

	void GameplayController::updateRemainingTime()
	{
		remaining_time -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	float GameplayController::getRemainingTime()
	{
		return remaining_time;
	}

	int GameplayController::getMinesCount()
	{
		return board_service->getMinesCount();
	}
}
