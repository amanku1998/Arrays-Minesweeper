#pragma once
#include "../../UI/UIElement/ButtonView.h"
#include "../../UI/UIElement/ImageView.h"

namespace Gameplay
{
	namespace Cell
	{
		using namespace UI::UIElement;

		class CellController;

		class CellView
		{
		private:
			const int tile_size = 32;

			UI::UIElement::ButtonView* cell_button;

			CellController* cell_controller;
			int slice_count = 12;

			void initializeButtonImage(float width, float height);

		public:
			CellView(CellController* controller);
			~CellView();

			void initialize();
			void update();
			void render();
			void setCellTexture();
		};
	}
}