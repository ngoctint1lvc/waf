CFLAGS= -Wall -shared -fPIC -I/usr/include/lua5.1 -llua5.1

all: decision_tree.so random_forest.so test

decision_tree.so: decision_tree.c
	gcc -o decision_tree.so $(CFLAGS) decision_tree.c

random_forest.so: random_forest.c
	gcc -o random_forest.so $(CFLAGS) random_forest.c

test:
	ls ./tests/*.lua | xargs -n 1 lua

clean:
	rm *.so