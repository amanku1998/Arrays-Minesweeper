#pragma once
#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		using namespace UI::UIElement;

		class BoardService
		{
		public:

			BoardService();
			~BoardService();

			void initialize();
			void update();
			void render();
			void resetBoard();
			int getMinesCount();
			void processCellInput(CellController* cell_controller, ButtonType button_type);

		private:

			BoardController* board_controller;
			void destroy();
		};
	}
}