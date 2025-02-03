#pragma once

namespace Gameplay
{
	class GameplayController
	{
	private:
		const float max_duration = 301.f;
		float remaining_time;

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void restart();
		void updateRemainingTime();
		float getRemainingTime();
	};
}