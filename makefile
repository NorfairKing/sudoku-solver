CC = g++

SRC_DIR = src
TEST_DIR = test

WARNING_FLAGS = -Wall -Werror
SRC_DIR_FLAGS = -I$(SRC_DIR)
OPTIMISATION_FLAGS = -Ofast
STANDARD_FLAGS = -std=c++14
CFLAGS = \
	$(WARNING_FLAGS) \
	$(SRC_DIR_FLAGS) \
	$(OPTIMISATION_FLAGS) \
	$(STANDARD_FLAGS)

HEADER_EXT = h
SOURCE_EXT = cc
OBJECT_EXT = o
EXE_EXT 	 = bin

DIRTY_EXT = *.$(EXE_EXT) *.$(OBJECT_EXT)
DIRTY = $(DIRTY_EXT)

EXE_NAME = sudoku
EXE_BIN = $(EXE_NAME).$(EXE_EXT)

MAIN_SRC = $(SRC_DIR)/main.cc
SRCS = $(wildcard $(SRC_DIR)/*.$(SOURCE_EXT))
DEPS = $(wildcard $(SRC_DIR)/*.$(HEADER_EXT))
OBJS = $(SRCS:.$(SOURCE_EXT)=.$(OBJECT_EXT))


all: $(EXE_BIN)

$(EXE_BIN): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

%.$(OBJECT_EXT): %.$(SOURCE_EXT) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TESTSUITE = testsuite.$(EXE_EXT)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.$(SOURCE_EXT))
TEST_LIB_FLAGS = -lgtest
TEST_DIR_FLAGS = -I$(TEST_DIR)
TEST_OUT_FLAG  = -o $(TESTSUITE)
TEST_FLAGS = \
	$(CFLAGS) \
	$(TEST_LIB_FLAGS) \
	$(TEST_DIR_FLAGS) \
	$(TEST_OUT_FLAG)

test: $(TESTSUITE)
	./$(TESTSUITE)

$(TESTSUITE): $(TEST_SRCS)
	$(CC) $(TEST_SRCS) $(filter-out $(MAIN_SRC),$(SRCS)) $(TEST_FLAGS)

BENCHMARKER = benchmarker.$(EXE_EXT)
BM_DIR = benchmark
BM_SRCS = $(wildcard $(BM_DIR)/*.$(SOURCE_EXT))
BM_DIR_FLAGS = -I$(BM_DIR)
BM_OUT_FLAG = -o $(BENCHMARKER)
BM_FLAGS = \
	$(CFLAGS) \
	$(BM_DIR_FLAGS) \
	$(BM_OUT_FLAG)


benchmark: $(BENCHMARKER)
	./$(BENCHMARKER)

$(BENCHMARKER): $(BM_SRCS)
	$(CC) $(BM_SRCS) $(filter-out $(MAIN_SRC),$(SRCS)) $(BM_FLAGS)

clean:
	find . -name "*.$(OBJECT_EXT)" -type f -delete
	find . -name "*.$(EXE_EXT)"    -type f -delete


love:
	@echo not war
