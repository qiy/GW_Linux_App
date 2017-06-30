main: main.o DList.o
	gcc -o main main.o DList.o
List.o:DList.c DList.h
	gcc -c DList.c
main.o: main.c DList.h
	gcc -c main.c
clean: 
	rm -rf *.o
