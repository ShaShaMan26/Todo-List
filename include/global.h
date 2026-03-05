#include "list.h"

#define LISTS_SIZE 50

typedef struct {
	int running;
	int inList;
	
	// Global_t prevState; fix self-ref issue
	// Global_t succState;
	
	int length;
	List_t lists[LISTS_SIZE];
} Global_t;

// int getSize(Global_t* g);
// void resize(Global_t* g);
void init(Global_t* g);
int badIndex(Global_t* g, int i);
void add(Global_t* g, List_t* l);
void del(Global_t* g, int i);
void complete(Global_t* g, int i);
void move(Global_t* g, int i, int j);
void dispLists(Global_t* g);
void quit(Global_t* g);
void select(Global_t* g, int i);
void ret(Global_t* g);
void run(Global_t* g);

