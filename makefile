cc = g++
cflags = -c
cdflags = -g -c
ipath = -I$(inc)
src = ./src
inc = ./include
bin = ./bin

build: entry.o list.o global.o main.o
	$(cc) $(bin)/entry.o $(bin)/list.o $(bin)/global.o $(bin)/main.o -o $(bin)/todo

run:
	@$(MAKE) build
	@./bin/todo

dbuild: dentry.o dlist.o dglobal.o dmain.o
	$(cc) $(bin)/dentry.o $(bin)/dlist.o $(bin)/dglobal.o $(bin)/dmain.o -o $(bin)/dtodo

drun:
	@$(MAKE) dbuild
	@./bin/dtodo

main.o: $(inc)/main.h $(src)/main.c
	$(cc) $(cflags) $(inc)/main.h $(src)/main.c -o $(bin)/main.o $(ipath)

global.o: $(inc)/global.h $(src)/global.c
	$(cc) $(cflags) $(inc)/global.h $(src)/global.c -o $(bin)/global.o $(ipath)

entry.o: $(inc)/entry.h $(src)/entry.c
	$(cc) $(cflags) $(inc)/entry.h $(src)/entry.c -o $(bin)/entry.o $(ipath)

list.o: $(inc)/list.h $(src)/list.c
	$(cc) $(cflags) $(inc)/list.h $(src)/list.c -o $(bin)/list.o $(ipath)

dmain.o: $(inc)/main.h $(src)/main.c
	$(cc) $(cdflags) $(inc)/main.h $(src)/main.c -o $(bin)/dmain.o $(ipath)

dglobal.o: $(inc)/global.h $(src)/global.c
	$(cc) $(cdflags) $(inc)/global.h $(src)/global.c -o $(bin)/dglobal.o $(ipath)

dentry.o: $(inc)/entry.h $(src)/entry.c
	$(cc) $(cdflags) $(inc)/entry.h $(src)/entry.c -o $(bin)/dentry.o $(ipath)

dlist.o: $(inc)/list.h $(src)/list.c
	$(cc) $(cdflags) $(inc)/list.h $(src)/list.c -o $(bin)/dlist.o $(ipath)

