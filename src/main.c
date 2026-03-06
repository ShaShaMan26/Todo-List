#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "todo.h"

void run(Todo_t*);

int main(void) {
	Todo_t t;
	init(&t);
	// load(&global);
	while(t.running) {
		clear();
		run(&t);
	}
	// save(&global);
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~List menu~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void add(List_t* l) {
        Entry_t* e = (Entry_t*) malloc(sizeof(Entry_t));
        printf("Enter entry name: ");
        collectStr(e->title);
        printf("Enter entry description: ");
        collectStr(e->desc);

        add(l, e);
}

void del(List_t* l) {
        printf("Enter index to delete: ");
        int i = collectChar() - '0' - 1;
        del(l, i);
}

void move(List_t* l) {
        printf("Enter index to move: ");
        int i = collectChar() - '0' - 1;
        printf("Enter new index: ");
        int j = collectChar() - '0' - 1;
        move(l, i, j);
}

void ret(Todo_t* g) {
        g->inList = -1;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Main Menu~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void add(Todo_t* g) {
        List_t* l = (List_t*) malloc(sizeof(List_t));
        init(l);
        printf("Enter list name: ");
        collectStr(l->title);
        printf("Enter list description: ");
        collectStr(l->desc);

        add(g, l);
}

void del(Todo_t* g) {
        printf("Enter index to delete: ");
        int i = collectChar() - '0' - 1;
        del(g, i);
}

void move(Todo_t* g) {
        printf("Enter index to move: ");
        int i = collectChar() - '0' - 1;
        printf("Enter new index: ");
        int j = collectChar() - '0' - 1;
        move(g, i, j);
}
void select(Todo_t* g) {
        printf("Enter index to select: ");
        int i = collectChar() - '0' - 1;
        g->inList = i;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Global~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void quit(Todo_t* g) {
        g->running = 0;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Run~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void run(Todo_t* g) {
        // display correct header
	if (g->inList > -1) {
                dispList(&g->lists[g->inList]);
        } else {
                dispLists(g);
        }

	// get command
        printf("Enter command: ");
        char c = collectChar();
        
        // check for global commands
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

	// check entry commands
        if (g->inList > -1) {
                List_t* l = &g->lists[g->inList];
                switch(c) {
                        case 'a':
                                add(l);
                                break;
                        case 'd':
                                del(l);
                                break;
                        case 'c':
                                break;
                        case 'm':
                                move(l);
                                break;
                        case 'e':
                                break;
                        case 'r':
                                ret(g);
                                break;
                }
        } else {
                // check list commands
                switch (c) {
                        case 'a':
                                add(g);
                                break;
                        case 'd':
                                del(g);
                                break;
                        case 'c':
                                // printf("Enter index to complete: ");
                                // int i = collectChar() - '0' - 1;
                                // complete(g, i);
                                break;
                        case 'm':
                                move(g);
                                break;
                        case 'e':
                                break;
                        case 's':
                                select(g);
                                break;
                }
        }
}

