main: main.o List.o
	gcc -o main main.o List.o
List.o:List.c List.h
	gcc -c List.c
main.o: main.c List.h
	gcc -c main.c
clean: 
	rm -rf *.o
