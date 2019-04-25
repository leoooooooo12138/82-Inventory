all: inventory

inventory:

menu.o: menu.cpp
	g++ -c menu.cpp
main.o: main.cpp
	g++ -c main.cpp

inventory: menu.o main.o
	g++ menu.o main.o -o inventory

clean:
	rm -rf *.o inventory

.PHONY: clean
