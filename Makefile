main: main.o student.o
	g++ main.o student.o -o main 
	rm *.o

main.o: main.cpp student.h
	g++ -c main.cpp

clean:
	rm *.o
