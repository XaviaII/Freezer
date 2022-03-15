#pragma once

#ifdef FREEZER_PLATFORM_WINDOWS

extern Freezer::Application* Freezer::CreateApplication();
	
int main(int argc, char** argv) {

	Freezer::Log::Init();
	FREEZER_CORE_WARN("Initialized Log!");
	int a = 5;
	FREEZER_INFO("Hello! Var={0}", a);

	auto app = Freezer::CreateApplication();
	app->Run();
	delete app;
}

#endif