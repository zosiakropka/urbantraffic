target?=build

rebuild: clean all

all: $(target)/main.o $(target)/server.o $(target)/connection.o
	g++ $(target)/main.o $(target)/server.o $(target)/connection.o -Wall -lpthread -lboost_system -o build/main

$(target)/main.o: $(target) main.cpp
	gcc main.cpp -c -Wall -o $(target)/main.o

$(target)/connection.o: $(target) sources/msgr/connection.cpp
	gcc sources/msgr/connection.cpp -c -Wall -o $(target)/connection.o

$(target)/server.o: $(target) sources/msgr/server.cpp
	gcc sources/msgr/server.cpp -c -Wall -o $(target)/server.o

$(target):
	mkdir $(target)

clean:
	rm -rf $(target)
