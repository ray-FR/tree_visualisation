CC = gcc
CFLAGS = -Wall -O2
CPPFLAGS = -I.
LDFLAGS = -lm
HEADERS = include/textreader.h include/graph.h
SOURCES = src/textreader.c src/graph.c src/main.c
OBJ = $(patsubst src/%.c, build/%.o, $(SOURCES))
PROGNAME = graph
all: $(PROGNAME)

$(PROGNAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o build/$(PROGNAME)
build/%.o: src/%.c $(HEADERS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

