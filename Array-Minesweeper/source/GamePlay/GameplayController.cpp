#include "../../header/GamePlay/GameplayController.h"
#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Board;
	using namespace Main;
	using namespace UI::UIElement;

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
		if (isTimeOver())
			endGame(GameResult::LOST);
	}

	bool GameplayController::isTimeOver()
	{ 
		return (remaining_time <= 1); 
	}

	void GameplayController::render()
	{

	}

	void GameplayController::restart()
	{
		game_result = GameResult::NONE;
		board_service->resetBoard();
		remaining_time = max_duration;
	}

	void GameplayController::endGame(GameResult result)
	{
		switch (result)
		{
		case GameResult::WON:
			gameWon();
			break;
		case GameResult::LOST:
			gameLost();
			break;
		default:
			break;
		}
	}

	void GameplayController::updateRemainingTime()
	{
		if (game_result == GameResult::WON)
			return;

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

	void GameplayController::beginGameOverTimer() 
	{ 
		remaining_time = game_over_time; 
	}

	void GameplayController::showCredits() 
	{
		GameService::setGameState(GameState::CREDITS); 
	}

	//
	void GameplayController::gameWon()
	{
		game_result = GameResult::WON;
		board_service->flagAllMines();
		board_service->setBoardState(BoardState::COMPLETED);
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::GAME_WON);
	}

	void GameplayController::gameLost()
	{
		if (game_result == GameResult::NONE)
		{
			game_result = GameResult::LOST;
			beginGameOverTimer();
			board_service->showBoard();
			board_service->setBoardState(BoardState::COMPLETED);
		}
		else
		{
			showCredits();
		}
	}
}
