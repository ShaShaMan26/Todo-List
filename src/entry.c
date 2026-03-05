#include <stdio.h>
#include "entry.h"

void dispEntry(Entry_t* e) {
	printf("%s\n%s\n", e->title, e->desc);
}

void edit(Entry_t* e) {
	// query edit name
	// e -> title = input;
	// query edit desc
	// e -> desc = input;
}

