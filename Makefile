aoc: build/aoc
	ln -f -s build/aoc
build/aoc: aoc.c build/input1.o
	mkdir -p build
	gcc -o build/aoc -std=c11 -Wall -Werror -O2 build/input1.o aoc.c

build/input1.o: input1.txt
	mkdir -p build
	ld -r -b binary -o build/input1.o input1.txt
