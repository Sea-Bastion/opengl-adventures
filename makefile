DFLAGS = -g
CFLAGS = -lglut -lGL -lGLU -lGLEW `pkg-config --cflags --libs openal `

CC = g++
VERSION = c++17
INCLUDE = classes/cpp/*
HEADERS = -Iclasses/headers


run: compiled/release/main
	./$<

compiled/release/main: main.cpp
	$(CC) -o $@ $< $(INCLUDE) --std=$(VERSION) $(HEADERS) $(CFLAGS)

debug: compiled/debug/main
	gdb $<

compiled/debug/main: main.cpp
	$(CC) $(DFLAGS) -o $@ $< $(INCLUDE) --std=$(VERSION) $(HEADERS) $(CFLAGS)