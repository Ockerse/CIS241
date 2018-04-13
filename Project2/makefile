all: store.h store.o main.o
	gcc -o a.out store.o main.o

main.o: store.h main.c
	gcc -c main.c

store.o: store.h store.c
	gcc -c store.c

test:
	./a.out

clean:
	rm -f *.o a.out store 

