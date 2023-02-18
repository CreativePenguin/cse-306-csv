cc := gcc
CFLAGS := -std=c11

all: compile
	./csv 05020004-eng.csv

compile: main.o
	gcc $(CFLAGS) -o csv main.c

main.o:
	gcc $(CFLAGS) -c main.c

tests.o: tests.c main.c
	gcc $(CFLAGS) -c tests.c

tests: tests.o
	gcc $(CFLAGS) -o tests main.o tests.o

meanh: compile
	./csv -h -mean "Value" 05020004-eng.csv

clean:
	rm csv main.o tests.o
