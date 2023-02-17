all:
	gcc -o csv main.c
	./csv 05020004-eng.csv
debug:
	gcc -g -o csv main.c
	gdb ./csv 05020004-eng.csv

test:
	gcc tmp.c
	./a.out failure
clean:
	rm csv a.out tmp.c main.c~
