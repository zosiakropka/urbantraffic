target?=build

rebuild: clean all

all: $(target)/main.o $(target)/server.o $(target)/connection.o $(target)/message.o $(target)/subscriber.o $(target)/simulator.o
	g++ $(target)/main.o $(target)/server.o $(target)/connection.o $(target)/message.o $(target)/subscriber.o $(target)/simulator.o -Wall -lpthread -lboost_system -ljson -o build/main

$(target)/main.o: $(target) main.cpp
	gcc main.cpp -c -Wall -o $(target)/main.o

$(target)/connection.o: $(target) sources/msgr/connection.cpp
	gcc sources/msgr/connection.cpp -c -Wall -o $(target)/connection.o

$(target)/server.o: $(target) sources/msgr/server.cpp
	gcc sources/msgr/server.cpp -c -Wall -o $(target)/server.o

$(target)/message.o: $(target) sources/msgr/message.cpp
	gcc sources/msgr/message.cpp -c -Wall -o $(target)/message.o

$(target)/subscriber.o: $(target) sources/msgr/subscriber.cpp
	gcc sources/msgr/subscriber.cpp -c -Wall -o $(target)/subscriber.o

$(target)/simulator.o: $(target) sources/simulation/simulator.cpp
	gcc sources/simulation/simulator.cpp -c -Wall -o $(target)/simulator.o

$(target):
	mkdir $(target)

clean:
	rm -rf $(target)
