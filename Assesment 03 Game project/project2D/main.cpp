#include "MyApplication.h"
#include <crtdbg.h>
#include <ctime>
#include <cmath>


int main() {
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand((unsigned int)time(NULL));

	// allocation
	auto app = new MyApplication();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}