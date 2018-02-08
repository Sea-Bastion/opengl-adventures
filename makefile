DFLAGS = -g
CFLAGS = -lglut -lGL -lGLU -lGLEW `pkg-config --cflags --libs glfw3 openal`

CC = g++
VERSION = c++17
INCLUDE = 
HEADERS = -Iclasses/headers


run: compiled/release/main
	./$<

compiled/release/main: main.cpp
	$(CC) -o $@ $< $(INCLUDE) --std=$(VERSION) $(HEADERS) $(CFLAGS)

debug: compiled/debug/main
	gdb $<

compiled/debug/main: main.cpp
	$(CC) $(DFLAGS) -o $@ $< $(INCLUDE) --std=$(VERSION) $(HEADERS) $(CFLAGS)