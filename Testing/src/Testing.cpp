#include <Freezer.h>

class Testing : public Freezer::Application {
public:
	Testing() {

	}

	~Testing() {

	}
};

Freezer::Application* Freezer::CreateApplication() {
	return new Testing();
}