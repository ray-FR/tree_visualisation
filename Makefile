CC = gcc
RM = rm -f
TAR = tar
MKDIR = mkdir
CHMOD = chmod
CP = rsync -R
distdir = DM_IZEM_TEXT2BT
CFLAGS = -Wall -O2
CPPFLAGS = -I.
LDFLAGS = -lm
HEADERS = include/textreader.h include/struct.h include/graph.h include/arb.h 
SOURCES = src/textreader.c src/graph.c src/arb.c src/main.c
OBJ = $(patsubst src/%.c, build/%.o, $(SOURCES))
PROGNAME = graph
DISTFILES = $(SOURCES) Makefile $(HEADERS)
all: $(PROGNAME)

$(PROGNAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(PROGNAME)
build/%.o: src/%.c $(HEADERS)
	@mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

dist: distdir
	$(CHMOD) -R a+r $(distdir)
	$(TAR) zcvf $(distdir).tgz $(distdir)
	$(RM) -r $(distdir)

distdir: $(DISTFILES)
	$(RM) -r $(distdir)
	$(MKDIR) $(distdir)
	$(CHMOD) 777 $(distdir)
	$(CP) $(DISTFILES) $(distdir)

clean:
	@rm -f graph
	@rm -f build/*