# La ruta de tu instalación de clang o g++
CXX = clang++ -std=c++14

FLAGS = -g -O2 -Wall

INCLUDE = -I.

default: main

main: hanoi.o
	$(CXX) $(FLAGS) $(INCLUDE) $@.cpp -o $@  hanoi.o

hanoi.o: hanoi.cpp
	$(CXX) $(FLAGS) $(INCLUDE) -c hanoi.cpp

clean:
	$(RM) *~ *.o main 
