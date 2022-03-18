#pragma once

#include "Events/Event.h"
#include "Freezer/Events/ApplicationEvent.h"

#include "Window.h"
#include "Freezer/LayerStack.h"

namespace Freezer {
	class FREEZER_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// defined in CLIENT
	Application* CreateApplication();
}
