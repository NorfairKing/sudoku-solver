CC = cc
CFLAGS = 

HEADER_EXT = h
SOURCE_EXT = cc
OBJECT_EXT = o
EXE_EXT = bin

EXE_NAME = sudoku
EXE_BIN = $(EXE_NAME).$(EXE_EXT)

SRCS = $(wildcard *.$(SOURCE_EXT))
DEPS = $(wildcard *.$(HEADER_EXT))
OBJS = $(SRCS:.$(SOURCE_EXT)=.$(OBJECT_EXT))


all: $(EXE_BIN)

$(EXE_BIN): $(OBJS)
		gcc -o $@ $^ $(CFLAGS) $(LIBS)

%.$(OBJECT_EXT): %.$(SOURCE_EXT) $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

love:
	@echo not war
