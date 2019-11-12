all: devrandom.o
	gcc -o devrandom devrandom.o

devrandom.o: devrandom.c
	gcc -c devrandom.c

run:
	./devrandom

clean:
	rm *.o
	rm randomnumbers.txt
	rm *.~