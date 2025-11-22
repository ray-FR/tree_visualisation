CC = gcc
CFLAGS = -Wall -O2
CPPFLAGS = -I.
LDFLAGS = -lm
HEADERS = include/textreader.h include/graph.h include/arb.h
SOURCES = src/textreader.c src/graph.c src/arb.c src/main.c
OBJ = $(patsubst src/%.c, build/%.o, $(SOURCES))
PROGNAME = graph
all: $(PROGNAME)

$(PROGNAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(PROGNAME)
build/%.o: src/%.c $(HEADERS)
	@mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	@rm -f graph
	@rm -f build/*