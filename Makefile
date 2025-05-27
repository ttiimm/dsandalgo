CC = gcc
CFLAGS = -Iinclude
# TODO: dependencies can be generated from compiler 
DEPS = include/*.h

DS_OBJ = src/linkedlist.o

BIN_DIR = bin

# Find all test files structured like src/*_test.c
TEST_SRC = $(wildcard src/*_test.c)
# Build object files
TEST_OBJ = $(TEST_SRC:.c=.o)
# Define executables
TESTS = $(patsubst src/%.c,$(BIN_DIR)/%,$(TEST_SRC))

all: $(TESTS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Pattern rule: build an executable from its test object and the DS object
$(BIN_DIR)/%: src/%.o $(DS_OBJ) | $(BIN_DIR)
	$(CC) -o $@ $^ $(CFLAGS)

src/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f src/*.o $(TESTS)