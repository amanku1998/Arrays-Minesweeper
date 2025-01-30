#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Cell/CellController.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;

		BoardController::BoardController()
		{
			board_view = new BoardView(this);
			createBoard();
		}

		BoardController::~BoardController()
		{
			destroy();
		}

		void BoardController::createBoard()
		{
			//cell = new CellController();

			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i] = new CellController(i); //Passing Cell Index in Cell Controller's constructor
			}
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			initializeCells();
		}

		void BoardController::initializeCells()
		{
			float cell_width = board_view->getCellWidth();
			float cell_height = board_view->getCellHeight();
			
			//cell->initialize(cell_width, cell_height);
			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i]->initialize(cell_width, cell_height);
			}
		}

		void BoardController::update()
		{
			board_view->update();
			//cell->update();
			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i]->update();
			}
		}

		void BoardController::render()
		{
			board_view->render();
			//cell->render();
			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i]->render();
			}
		}

		void BoardController::reset()
		{
			//cell->reset();
			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i]->reset();
			}
		}

		void BoardController::deleteBoard()
		{
			//delete(cell);
			for (int i = 0; i < number_of_columns; i++)
			{
				delete(cells[i]);
			}
		}

		void BoardController::destroy()
		{
			deleteBoard();
			delete(board_view);
		}
	}
}