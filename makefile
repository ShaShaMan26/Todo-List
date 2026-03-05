cc = g++
cflags = -c
ipath = -I$(inc)
src = ./src
inc = ./include
bin = ./bin

build: entry.o list.o global.o main.o
	$(cc) $(bin)/entry.o $(bin)/list.o $(bin)/global.o $(bin)/main.o -o $(bin)/todo

main.o: $(inc)/main.h $(src)/main.c
	$(cc) $(cflags) $(inc)/main.h $(src)/main.c -o $(bin)/main.o $(ipath)

global.o: $(inc)/global.h $(src)/global.c
	$(cc) $(cflags) $(inc)/global.h $(src)/global.c -o $(bin)/global.o $(ipath)

entry.o: $(inc)/entry.h $(src)/entry.c
	$(cc) $(cflags) $(inc)/entry.h $(src)/entry.c -o $(bin)/entry.o $(ipath)

list.o: $(inc)/list.h $(src)/list.c
	$(cc) $(cflags) $(inc)/list.h $(src)/list.c -o $(bin)/list.o $(ipath)

