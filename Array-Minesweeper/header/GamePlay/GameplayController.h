#pragma once
#include "../../header/Gameplay/Board/BoardService.h"

namespace Gameplay
{
	using namespace Gameplay::Board;

	enum class GameResult
	{
		NONE,
		WON,
		LOST
	};

	class GameplayController
	{
	private:
		const float max_duration = 301.f;
		float remaining_time;
		const float game_over_time = 11.f;

		BoardService* board_service;
		GameResult game_result = GameResult::NONE;

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void restart();
		void endGame(GameResult result);
		void updateRemainingTime();
		float getRemainingTime();

		int getMinesCount();
		void beginGameOverTimer();
		void showCredits();
		void gameLost();
		void gameWon();
		bool isTimeOver();
	};
}