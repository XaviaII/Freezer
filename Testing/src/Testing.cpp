#include <Freezer.h>

class ExampleLayer : public Freezer::Layer {
public:
	ExampleLayer() : Layer("Example") {

	}

	void OnUpdate() override {
		FREEZER_INFO("ExampleLayer::Update");
	}

	void OnEvent(Freezer::Event& event) override {
		FREEZER_TRACE("{0}", event);
	}
};

class Testing : public Freezer::Application {
public:
	Testing() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Freezer::ImGuiLayer());
	}

	~Testing() {

	}
};

Freezer::Application* Freezer::CreateApplication() {
	return new Testing();
}