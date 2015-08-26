CC = g++

SRC_DIR = src

WARNING_FLAGS = -Wall -Werror
SRC_DIR_FLAGS = -I$(SRC_DIR)
CFLAGS = \
	$(WARNING_FLAGS) \
	$(SRC_DIR_FLAGS)

HEADER_EXT = h
SOURCE_EXT = cc
OBJECT_EXT = o
EXE_EXT = bin

DIRTY_EXT = *.$(EXE_EXT) *.$(OBJECT_EXT)
DIRTY = $(DIRTY_EXT)

EXE_NAME = sudoku
EXE_BIN = $(EXE_NAME).$(EXE_EXT)

SRCS = $(wildcard src/*.$(SOURCE_EXT))
DEPS = $(wildcard src/*.$(HEADER_EXT))
OBJS = $(SRCS:.$(SOURCE_EXT)=.$(OBJECT_EXT))


all: $(EXE_BIN)

$(EXE_BIN): $(OBJS)
		$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

%.$(OBJECT_EXT): %.$(SOURCE_EXT) $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(DIRTY)

love:
	@echo not war
