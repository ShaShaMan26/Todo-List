#include "entry.h"

typedef struct {
	Entry_t entries[];
	int length;

	char title[];
	char desc[];
} List_t;

int getSize(List_t* l);
void resize(List_t* l);

