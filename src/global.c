#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear() {
	printf("\033[2J\033[1;1H");
}

void collectStr(char* str) {
        char buff[1024];
        scanf(" %[^\n]s", buff);
        strcpy(str, buff);
        str[sizeof(str) - 1] = '\0';
}

char collectChar() {
        char* s = (char*) malloc(2);
        collectStr(s);
        char c = *s;
        free(s);
        return c;
}

