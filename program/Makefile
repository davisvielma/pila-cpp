OPC = -I../include -g -c -std=c++11

all: pila.exe

pila.exe:   main.o Pila.o Controlador.o
	g++  -o $@ $^

main.o: main.cpp
	g++ $(OPC) $<

Pila.o: ../src/Pila.cpp
	g++ $(OPC) $<


Controlador.o: ../src/Controlador.cpp
	g++ $(OPC) $<

clean:
	rm -fr *.o *.exe