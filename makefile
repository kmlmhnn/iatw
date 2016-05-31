CC=gcc
CFLAGS=-Wall -c -g3
LDFLAGS=-lncurses

all: snow

snow: main.o display.o player.o
	$(CC)  main.o display.o player.o -o snow $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) main.c

display.o: display.c
	$(CC) $(CFLAGS) display.c

player.o: player.c
	$(CC) $(CFLAGS) player.c

clean:
	rm -f *o *~ snow

