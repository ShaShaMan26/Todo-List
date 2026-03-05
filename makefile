cc = g++
cflags = -c
ipath = -I$(inc)
src = ./src
inc = ./include
bin = ./bin

build: entry.o list.o
	$(cc) $(bin)/entry.o $(bin)/list.o -o $(bin)/todo

entry.o: $(inc)/entry.h $(src)/entry.c
	$(cc) $(cflags) $(inc)/entry.h $(src)/entry.c -o $(bin)/entry.o $(ipath)

list.o: $(inc)/list.h $(src)/list.c
	$(cc) $(cflags) $(inc)/list.h $(src)/list.c -o $(bin)/list.o $(ipath)

