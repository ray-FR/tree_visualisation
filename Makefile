CC = gcc
CFLAGS = -Wall -O2
CPPFLAGS = -I.
LDFLAGS = -lm
HEADERS = textreader.h graph.h
SOURCES = textreader.c graph.c main.c
OBJ = $(SOURCES:.c=.o)
PROGNAME = test
all: $(PROGNAME)
$(PROGNAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(PROGNAME)
%.o: %.c $(HEADERS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

