#include <stdio.h>
#include "input.h"

char collectChar() {
	char c;
	// c = getchar();
	scanf("%c", &c); // not working
	scanf(" [^\n]");
	return c;
}

