#include "main.h"

int main(void) {
	Global_t global;
	// init(&global); (?)
	// load(&global);
	while(global.running) {
		run(&global);
	}
	// save(&global);
}

