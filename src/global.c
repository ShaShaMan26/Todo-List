#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"

void run(Global_t* g) {
	// clear();
	// printf("The length of Lists is now [%d]\n", g->length);

	if (g->inList > -1) {
		dispList(&g->lists[g->inList]);
	} else {
		dispLists(g);
	}

	printf("Enter command: ");
	char c = collectChar();
	
	// global
	switch (c) {
		case 'q':
			quit(g);
			break;
		case 'z':
			// undo(g);
			break;
		case 'y':
			// redo(g);
			break;
	}

	if (g->inList > -1) {
		// entry commands
		switch(c) {
			case 'a':
				break;
			case 'd':
				break;
			case 'e':
				break;
			case 'm':
				break;
			case 'r':
				ret(g);
				break;
		}
	} else {
		// list commands
		switch (c) {
			case 'd': {
				printf("Enter index to delete: ");
				int i = collectChar() - '0' - 1;
				del(g, i);
				break;
			}
			case 'c': {
				// printf("Enter index to complete: ");
				// int i = collectChar() - '0' - 1;
				// complete(g, i);
				break;
			}
			case 'm': {
				printf("Enter index to move: ");
				int i = collectChar() - '0' - 1;
				printf("Enter new index: ");
				int j = collectChar() - '0' - 1;
				move(g, i, j);
				break;
			}
			case 'e':
				break;
			case 's': {
				printf("Enter index to select: ");
				int i = collectChar() - '0' - 1;
				select(g, i);
				break;
			}
			case 'a': {
				List_t* l = (List_t*) malloc(sizeof(List_t));
				init(l);

				printf("Enter list name: ");
				collectStr(l->title); 
				printf("Enter list description: ");
				collectStr(l->desc);

				add(g, l);
				break;
			}		
		}
	}
}

void init(Global_t* g) {
	g->running = 1;
	ret(g);
	g->length = 0;
}

void dispLists(Global_t* g) {
	printf("Lists:\n");
	if (g->length < 1) {
		printf("[!] No lists found.\n");
		return;
	}
	for (int i = 0; i < g->length; i++) printf("[%d] %s\n", i + 1, g->lists[i].title);
}

// int getSize(Global_t* g) {
	// return sizeof(g->lists) / sizeof(g->lists[0]); need to rethink cuz mem and shit
//	return 0;
//}

//void resize(Global_t* g) {
//	List_t en[getSize(g->lists) + 10];
//	for (int i = 0; i < g->length; en[i] = g->lists[i], i++);
	// l->entries = en; fix cuz mem stuff
//}

int badIndex(Global_t* g, int i) {
	return i < 0 || i >= g->length;
}

void add(Global_t* g, List_t* l) {
	if (g->length < LISTS_SIZE) {
		g->lists[g->length++] = *l;
		return;
	}
	// print err
}

void del(Global_t* g, int i) {
	if (badIndex(g, i)) {
		// display err msg
		return;
	}
	// free(&g->lists[i]);
	for (; i < g->length - 1; g->lists[i] = g->lists[i + 1], i++);
	g->length--;
}

void complete(Global_t* g, int i) {
	if (badIndex(g, i)) {
		// display err msg
		return;
	}
	// write to file
	del(g, i);
}

void move(Global_t* g, int i, int j) {
	if (badIndex(g, i) || badIndex(g, j)) {
		// display err msg
		return;
	}
	List_t temp = g->lists[i];
	g->lists[i] = g->lists[j];
	g->lists[j] = temp;
}

void quit(Global_t* g) {
	g->running = 0;
}

void select(Global_t* g, int i) {
	if (badIndex(g, i)) {
		// display err
		return;
	}
	g->inList = i;
}

void ret(Global_t* g) {
	g->inList = -1;
}

