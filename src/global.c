#include <stdio.h>
#include "global.h"

void run(Global_t* g) {
	if (g->inList > -1) {
		dispList(&g->lists[g->inList]);
	} else {
		dispLists(g);
	}
	char c;
	// c = get command char
	
	// global
	switch (c) {
	}

	if (g->inList > -1) {
		// entry commands
		switch(c) {
		}
	} else {
		// list commands
		switch (c) {
		}
	}
}

void init(Global_t* g) {
	g->running = 1;
	ret(g);
	g->length = 0;
}

void dispLists(Global_t* g) {
	if (g->length < 1) {
		printf("[!] No lists found.\n");
		return;
	}
	for (int i = 0; i < g->length; i++) printf("[%d] %s\n", i, g->lists[i].title);
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
	if (g->length > LISTS_SIZE) {
		// print err
		return;
	}
	g->lists[g->length++] = *l;
	// if (++(g->length) >= getSize(g)) resize(g);
}

void del(Global_t* g, int i) {
	if (badIndex(g, i)) {
		// display err msg
		return;
	}
	for (; i < g->length - 1; g->lists[i] = g->lists[++i]);
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

