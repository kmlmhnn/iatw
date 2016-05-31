CC=gcc
CFLAGS=-Wall -c -g3
LDFLAGS=-lncurses

all: iatw

iatw: main.o display.o player.o save.o
	$(CC)  main.o display.o player.o save.o -o iatw $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) main.c

display.o: display.c
	$(CC) $(CFLAGS) display.c

player.o: player.c
	$(CC) $(CFLAGS) player.c

save.o: save.c
	$(CC) $(CFLAGS) save.c

clean:
	rm -f *o *~ iatw

