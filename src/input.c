#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"

char collectChar() {
	char* s = (char*) malloc(2);
	collectStr(s);
	char c = *s;
	free(s);
	return c;
}

void collectStr(char* str) {
	char buff[1024];
	scanf(" %[^\n]s", buff);
	strcpy(str, buff);
	str[sizeof(str) - 1] = '\0';
}

