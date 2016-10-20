FLAGS=-pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm
COMPILLER=g++

all: start

start: main.o
	$(COMPILLER) $(FLAGS) -o os-lab2 main.o

main.o: main.cpp
	$(COMPILLER) -c $(FLAGS) main.cpp

handler: handler.cpp
	$(COMPILLER) $(FLAGS) -o handler handler.cpp

clear:
	-rm -f *.o *.gch handler os-lab2
