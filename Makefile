# http://stackoverflow.com/a/2481326
# http://stackoverflow.com/a/1080180

all: main

debug: CPPFLAGS+=-DDEBUG
debug: main

main: main.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

main.o: main.cpp

clean:
	rm -rf main main.o
