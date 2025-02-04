#pragma once
#include "../../header/Gameplay/Board/BoardService.h"

namespace Gameplay
{
	using namespace Gameplay::Board;

	class GameplayController
	{
	private:
		const float max_duration = 301.f;
		float remaining_time;

		BoardService* board_service;

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void restart();
		void updateRemainingTime();
		float getRemainingTime();

		int getMinesCount();
	};
}