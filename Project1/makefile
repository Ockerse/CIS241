all: functions.h functions.o p1.o
	gcc -o a.out functions.o p1.o

p1.o: functions.h p1.c
	gcc -c p1.c

functions.o: functions.h functions.c
	gcc -c functions.c

enc: 
	./a.out e GOODMORNING data cipher

dec: 
	./a.out d GOODMORNING cipher ddata

test:
	./a.out e GOODMORNING data cipher
	./a.out d GOODMORNING cipher ddata
	diff -s data ddata

clean:
	rm -f *.o a.out cipher ddata

