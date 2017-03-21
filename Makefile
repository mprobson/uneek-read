# http://stackoverflow.com/a/2481326
# http://stackoverflow.com/a/1080180
CXXFLAGS=-O3

all: uneek

debug: CPPFLAGS+=-DDEBUG
debug: uneek

uneek: main.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

main.o: main.cpp

clean:
	rm -rf uneek main.o
