CC := clang
CFLAGS :=
LDFLAGS := -lm

all: creditcard

clean:
	rm -f creditcard

creditcard: creditcard.c
	$(CC) $(CFLAGS) -o creditcard creditcard.c $(LDFLAGS)

.PHONY: all clean
