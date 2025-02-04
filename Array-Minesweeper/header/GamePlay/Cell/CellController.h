#pragma once
#include "../../header/Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		class CellView;
		class CellModel;

		class CellController
		{
		private:
			CellView* cell_view;
			CellModel* cell_model;

			void destroy();

		public:
			CellController(sf::Vector2i pos);
			~CellController();

			void initialize(float cell_width, float cell_height);
			void update();
			void render();

			CellState getCellState();
			void setCellState(CellState state);

			CellValue getCellValue();
			void setCellValue(CellValue value);

			sf::Vector2i getCellPosition();
			void openCell();
			void flagCell();
			bool canOpenCell();

			void reset();
		};
	}
}