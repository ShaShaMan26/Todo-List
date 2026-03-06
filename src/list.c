#include <stdio.h>
#include "list.h"

//int getSize(List_t* l) {
	// return sizeof(l->entries) / sizeof(l->entries[0]); need to rethink cuz mem and shit
//	return 0;
//}

// void resize(List_t* l) {
// 	Entry_t en[getSize(l) + 10];
//	for (int i = 0; i < l->length; en[i] = l->entries[i], i++);
	// l->entries = en; fix cuz mem stuff
//}

void init(List_t* l) {
	l->length = 0;
}

int badIndex(List_t* l, int i) {
	return i < 0 || i >= l->length;
}

void add(List_t* l, Entry_t* e) {
	if (l->length < ENTRIES_SIZE) {
		l->entries[l->length++] = *e;
		return;
	}
	// print err
}

void del(List_t* l, int i) {
	if (badIndex(l, i)) {
		// display err msg
		return;
	}
	for (; i < l->length - 1; l->entries[i] = l->entries[i + 1], i++);
	l->length--;
}

void complete(List_t* l, int i) {
	if (badIndex(l, i)) {
		// display err msg
		return;
	}
	// write to file
	del(l, i);
}

void move(List_t* l, int i, int j) {
	if (badIndex(l, i) || badIndex(l, j)) {
		// display err msg
		return;
	}
	Entry_t temp = l->entries[i];
        if (i < j)
                for (; i < j; l->entries[i] = l->entries[i+1], i++);
        else if (i > j)
                for (; i > j; l->entries[i] = l->entries[i - 1], i--);
        else
                return;
        l->entries[j] = temp;
}

void dispList(List_t* l) {
	printf("%s\n%s\n", l->title, l->desc);
	if (l->length < 1) {
		printf("[!] No entries found.\n");
		return;
	}
	for (int i = 0; i < l->length; i++) printf("[%d] %s\n", i + 1, l->entries[i].title);
}

void edit(List_t* l) {
	// do the edit shit
}

