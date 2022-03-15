#pragma once

#include "Core.h"
#include "Events/Event.h"

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
