all: main.o products.o
	gcc -o products main.o products.o

main.o: main.c products.h
	gcc -c main.c

products.o: products.c
	gcc -c products.c

run:
	./products