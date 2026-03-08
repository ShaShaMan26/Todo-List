cc = g++
cflags = -c
cdflags = -g -c
ipath = -I$(inc)
src = ./src
inc = ./include
bin = ./bin

build: todo.o global.o main.o
	$(cc) $(bin)/todo.o $(bin)/global.o $(bin)/main.o -o $(bin)/todo
	@make clean

run:
	@$(MAKE) build
	@./bin/todo

dbuild: dtodo.o dglobal.o dmain.o
	$(cc) $(bin)/dtodo.o $(bin)/dglobal.o $(bin)/dmain.o -o $(bin)/dtodo
	@make clean

drun:
	@$(MAKE) dbuild
	@./bin/dtodo


main.o: $(src)/main.c
	$(cc) $(cflags) $(src)/main.c -o $(bin)/main.o $(ipath)

global.o: $(inc)/global.h $(src)/global.c
	$(cc) $(cflags) $(inc)/global.h $(src)/global.c -o $(bin)/global.o $(ipath)

todo.o: $(inc)/todo.h $(src)/todo.c
	$(cc) $(cflags) $(inc)/todo.h $(src)/todo.c -o $(bin)/todo.o $(ipath)


dmain.o: $(src)/main.c
	$(cc) $(cdflags) $(src)/main.c -o $(bin)/dmain.o $(ipath)

dglobal.o: $(inc)/global.h $(src)/global.c
	$(cc) $(cdflags) $(inc)/global.h $(src)/global.c -o $(bin)/dglobal.o $(ipath)

dtodo.o: $(inc)/todo.h $(src)/todo.c
	$(cc) $(cdflags) $(inc)/todo.h $(src)/todo.c -o $(bin)/dtodo.o $(ipath)

clean:
	rm -f $(bin)/*.o
