CC = gcc
CFLAGS = -Iinclude
# TODO: dependencies can be generated from compiler 
DEPS = include/*.h
OBJ = test.o linkedlist.o

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o test