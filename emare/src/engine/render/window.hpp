#pragma once

namespace emare
{
	struct viewport_initialization_params;

	class window
	{
	public:
		explicit window(viewport_initialization_params& initialization_params);
		void update();
	};
}
