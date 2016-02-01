CFLAGS = -g

all: obj bin stack.o stack_min.o queue.o set_stack.o
	gcc $(CFLAGS) -o bin/test -Iinclude src/test.c obj/stack.o obj/node.o obj/queue.o
	gcc $(CFLAGS) -o bin/problem_01 src/problem_01.c
	gcc $(CFLAGS) -o bin/problem_02 -Iinclude src/problem_02.c obj/stack_min.o obj/node.o obj/stack.o
	gcc $(CFLAGS) -o bin/problem_03 -Iinclude src/problem_03.c obj/stack.o obj/set_stack.o obj/node.o


queue.o: node.o
	gcc $(CFLAGS) -O -c -o obj/queue.o -Iinclude src/queue.c

stack_min.o: node.o stack.o
	gcc $(CFLAGS) -O -c -o obj/stack_min.o -Iinclude src/stack_min.c

stack.o: node.o
	gcc $(CFLAGS) -O -c -o obj/stack.o -Iinclude src/stack.c

set_stack.o: node.o
	gcc $(CFLAGS) -O -c -o obj/set_stack.o -Iinclude src/set_stack.c

node.o:
	gcc $(CFLAGS) -O -c -o obj/node.o -Iinclude src/node.c

bin:
	mkdir bin

obj:
	mkdir obj

clean:
	rm bin/*; rm obj/*; find . -iname "*~" -delete
