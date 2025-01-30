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
			CellController();
			~CellController();

			void initialize(float cell_width, float cell_height);
			void update();
			void render();

			CellState getCellState();
			CellValue getCellValue();

			void reset();
		};
	}
}