CFLAGS = -g

all: stack.o
	gcc $(CFLAGS) -o bin/problem_01 -Iinclude src/problem_01.c bin/stack.o bin/node.o

stack.o: node.o
	gcc $(CFLAGS) -O -c -o bin/stack.o -Iinclude src/stack.c

node.o:
	gcc $(CFLAGS) -O -c -o bin/node.o -Iinclude src/node.c

clean:
	rm bin/*; find . -iname "*~" -delete
