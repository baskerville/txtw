NAME = txtw
VERSION = 0.2

CC       = gcc
LIBS     = -lm -lcairo
CFLAGS  += -std=c99 -pedantic -Wall -Wextra -I$(PREFIX)/include
CFLAGS  += -D_POSIX_C_SOURCE=200112L -DVERSION=\"$(VERSION)\"
LDFLAGS += -L$(PREFIX)/lib

PREFIX    ?= /usr/local
BINPREFIX  = $(PREFIX)/bin

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: CFLAGS  += -Os
all: LDFLAGS += -s
all: $(NAME)

include Sourcedeps

$(OBJ): Makefile

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	 $(CC) -o $@ $(OBJ) $(LDFLAGS) $(LIBS)

install:
	mkdir -p "$(DESTDIR)$(BINPREFIX)"
	cp -p $(NAME) "$(DESTDIR)$(BINPREFIX)"

uninstall:
	rm -f "$(DESTDIR)$(BINPREFIX)"/$(NAME)
doc:
	pandoc --no-wrap -t json doc/README.md | runhaskell doc/man_filter.hs | pandoc --no-wrap -f json -t man --template doc/man.template -V name=$(NAME) -o $(NAME).1
	pandoc --no-wrap -f markdown -t asciidoc doc/README.md -o README.asciidoc

clean:
	rm -f $(OBJ) $(NAME)

.PHONY: all install uninstall doc clean
