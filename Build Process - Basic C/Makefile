Output/main.o: User/src/main.c
	gcc -c -I./User/inc User/src/main.c -o Output/main.o
Output/sum.o: User/src/sum.c
	gcc -c -I./User/inc User/src/sum.c -o Output/sum.o

build: Output/main.o Output/sum.o
	gcc Output/main.o Output/sum.o -o Output/main.exe

run: 
	Output/main.exe

clean: 
	rm -rf ./Output/*