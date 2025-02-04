#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../UI/UIElement/ButtonView.h"
#include <random>

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		using namespace UI::UIElement;
		class BoardView;

		enum class BoardState
		{
			FIRST_CELL,       // The state when the player opens first cell.
			PLAYING,          // The game is in progress.
			COMPLETED,    // The game is over.
		};

		class BoardController
		{
		public:

			static const int number_of_rows = 9;
			static const int number_of_columns = 9;
			static const int mines_count = 8;

			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();
			void reset();

			int getMinesCount();

			void processCellInput(CellController* cell_controller, ButtonType button_type);

			BoardState getBoardState();
			void setBoardState(BoardState state);

		private:

			BoardView* board_view;
			Cell::CellController* board[number_of_rows][number_of_columns];

			std::default_random_engine random_engine;
			std::random_device random_device;

			BoardState board_state;
			int flagged_cells;

			void populateBoard(sf::Vector2i cell_position);
			void populateMines(sf::Vector2i cell_position);
			void pupulateCells();

			void openCell(sf::Vector2i cell_position);
			void flagCell(sf::Vector2i cell_position);

			int countMinesAround(sf::Vector2i cell_position);
			bool isValidCellPosition(sf::Vector2i cell_position);

			void createBoard();
			void initializeCells();
			void destroy();
			void resetBoard();
			void deleteBoard();
		};
	}
}