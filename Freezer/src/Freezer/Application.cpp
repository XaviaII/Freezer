#include "Freezerpch.h"
#include "Application.h"

#include "Freezer/Events/ApplicationEvent.h"
#include "Freezer/LogSystem.h"

namespace Freezer {


	Application::Application() {
	}



	Application::~Application() {
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			FREEZER_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			FREEZER_TRACE(e);
		}

		while (true);
	}

}