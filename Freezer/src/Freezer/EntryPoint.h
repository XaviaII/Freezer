#pragma once

#ifdef FREEZER_PLATFORM_WINDOWS

extern Freezer::Application* Freezer::CreateApplication();
	
int main(int argc, char** argv) {
	auto app = Freezer::CreateApplication();
	app->Run();
	delete app;
}

#endif