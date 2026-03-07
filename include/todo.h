// entry
typedef struct {
        char title[51];
        char desc[101];
} Entry_t;
void dispEntry(Entry_t*);

// list
#define ENTRIES_SIZE 100
typedef struct {
        char title[51];
        char desc[101];

        int length;
        Entry_t entries[ENTRIES_SIZE];
} List_t;
void dispList(List_t*);
void dispEntries(List_t*);
void init(List_t*);
int badIndex(List_t*, int);
void add(List_t*, Entry_t*);
void del(List_t*, int);
void move(List_t*, int, int);

// todo
#define LISTS_SIZE 50
typedef struct {
        int running;
        int inList;

        // Global_t prevState; fix self-ref issue
        // Global_t succState;

        int length;
        List_t lists[LISTS_SIZE];
} Todo_t;
void dispLists(Todo_t*);
void init(Todo_t*);
int badIndex(Todo_t*, int);
void add(Todo_t*, List_t*);
void del(Todo_t*, int);
void move(Todo_t*, int, int);

