all: main.o
	gcc -o products main.o

main.o: main.c
	gcc -c main.c

run:
	./products