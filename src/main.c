#include <stdio.h>
#include "main.h"

int main(void) {
	Global_t global;
	init(&global);
	// load(&global);
	while(global.running) {
		// clear();
		run(&global);
	}
	// save(&global);
}

void clear() {
	printf("\033[2J\033[1;1H");
}

