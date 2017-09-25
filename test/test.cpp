#include "../app/include/tlc.h"

class TestGui : public Centauri::TLC {

};

int main(void) {
	auto t = new TestGui();
	t->init();
	auto window = t->createWindow();
	while (true) {
		window->loop();
	}
	t->test();
}