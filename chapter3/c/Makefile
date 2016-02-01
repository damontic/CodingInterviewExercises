CFLAGS = -g

all: stack.o stack_min.o queue.o
	gcc $(CFLAGS) -o bin/test -Iinclude src/test.c bin/stack.o bin/node.o bin/queue.o
	gcc $(CFLAGS) -o bin/problem_01 src/problem_01.c
	gcc $(CFLAGS) -o bin/problem_02 -Iinclude src/problem_02.c bin/stack_min.o bin/node.o bin/stack.o


queue.o: node.o
	gcc $(CFLAGS) -O -c -o bin/queue.o -Iinclude src/queue.c

stack_min.o: node.o stack.o
	gcc $(CFLAGS) -O -c -o bin/stack_min.o -Iinclude src/stack_min.c

stack.o: node.o
	gcc $(CFLAGS) -O -c -o bin/stack.o -Iinclude src/stack.c

node.o:
	gcc $(CFLAGS) -O -c -o bin/node.o -Iinclude src/node.c

clean:
	rm bin/*; find . -iname "*~" -delete
