#include "list.h"

typedef struct {
	int running;
	int inList;
	
	Global_t prevState;
	GLobal_t succState;
	
	int length;
	List_t lists[];
} Global_t;

int getSize(Global_t* g);
void resize(Global_t* g);

