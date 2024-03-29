CC := clang
CFLAGS := 

all: bigrams

clean:
	rm -f bigrams

bigrams: bigrams.c
	$(CC) $(CFLAGS) -o bigrams bigrams.c

.PHONY: all clean
