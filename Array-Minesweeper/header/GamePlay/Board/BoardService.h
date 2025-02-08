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
			BoardState getBoardState();
			void setBoardState(BoardState state);
			void flagAllMines();
			void processCellInput(CellController* cell_controller, ButtonType button_type);
			void showBoard();

		private:

			BoardController* board_controller;
			void destroy();
		};
	}
}