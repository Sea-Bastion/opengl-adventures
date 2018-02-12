DFLAGS = -g
CFLAGS = -Wall -lglut -lGL -lGLU -lGLEW -lSOIL `pkg-config --cflags --libs glfw3 openal`

CC = g++
VERSION = c++17
INCLUDE = classes/cpp/*
HEADERS = -Iclasses/headers

#binary directory
BINDIR = compiled/release
#debug directory
DBUGDIR = compiled/debug


run: $(BINDIR)/main
	./$<

$(BINDIR)/main: main.cpp $(INCLUDE)
	$(CC) -o $@ $^ --std=$(VERSION) $(HEADERS) $(CFLAGS)

debug: $(DBUGDIR)/main
	gdb $<

$(DBUGDIR)/main: main.cpp $(INCLUDE) 
	$(CC) $(DFLAGS) -o $@ $^ --std=$(VERSION) $(HEADERS) $(CFLAGS)

