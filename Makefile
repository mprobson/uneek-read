all: main

main: main.cpp
	g++ -o $@ $^

clean:
	rm -rf main
