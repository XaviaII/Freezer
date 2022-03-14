#pragma once

#include "Core.h"

namespace Freezer {
	class FREEZER_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// defined in CLIENT
	Application* CreateApplication();
}
