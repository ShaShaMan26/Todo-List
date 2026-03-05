#include "list.h"

typedef struct {
	int running;
	int inList;
	
	List_t lists[];
	int length;

	Global_t prevState;
	GLobal_t succState;
} Global_t;

int getSize(Global_t* g);
void resize(Global_t* g);

