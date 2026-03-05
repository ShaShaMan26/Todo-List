#include "entry.h"

#define ENTRIES_SIZE 100

typedef struct {
	char title[51];
	char desc[101];
	
	int length;
	Entry_t entries[ENTRIES_SIZE];
} List_t;

// int getSize(List_t* l);
// void resize(List_t* l);
int badIndex(List_t* l);
void add(List_t* l, Entry_t* e);
void del(List_t* l, int i);
void complete(List_t* l, int i);
void move(List_t* l, int i, int j);
void dispList(List_t* l);
void edit(List_t* l);

