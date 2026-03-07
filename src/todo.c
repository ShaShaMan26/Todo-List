#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "todo.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~entry~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void edit(Entry_t* e) {
        // query edit name
        // e -> title = input;
        // query edit desc
        // e -> desc = input;
}

void dispEntry(Entry_t* e) {
	printf("%s\n%s\n", e->title, e->desc);
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~lists~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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

void dispEntries(List_t* l) {
        printf("%s\n%s\n", l->title, l->desc);
        if (l->length < 1) {
                printf("[!] No entries found.\n");
                return;
        }
        for (int i = 0; i < l->length; i++) printf("[%d] %s\n", i + 1, l->entries[i].title);
}

void dispList(List_t* l) {
	printf("%s\n%s\n", l->title, l->desc);
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ todo ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void init(Todo_t* g) {
        g->running = 1;
        g->inList = -1;
        g->length = 0;
}

void dispLists(Todo_t* g) {
        printf("Lists:\n");
        if (g->length < 1) {
                printf("[!] No lists found.\n");
                return;
        }
        for (int i = 0; i < g->length; i++) printf("[%d] %s\n", i + 1, g->lists[i].title);
}

int badIndex(Todo_t* g, int i) {
        return i < 0 || i >= g->length;
}

void add(Todo_t* g, List_t* l) {
        if (g->length < LISTS_SIZE) {
                g->lists[g->length++] = *l;
                return;
        }
        // print err
}

void del(Todo_t* g, int i) {
        if (badIndex(g, i)) {
                // display err msg
                return;
        }
        // free(&g->lists[i]);
        for (; i < g->length - 1; g->lists[i] = g->lists[i + 1], i++);
        g->length--;
}

void move(Todo_t* g, int i, int j) {
        if (badIndex(g, i) || badIndex(g, j)) {
                // display err msg
                return;
        }
        List_t temp = g->lists[i];
        if (i < j)
                for (; i < j; g->lists[i] = g->lists[i+1], i++);
        else if (i > j)
                for (; i > j; g->lists[i] = g->lists[i - 1], i--);
        else
                return;
        g->lists[j] = temp;
}

