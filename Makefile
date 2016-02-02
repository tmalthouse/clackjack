CC = /usr/bin/gcc
CFLAGS = -O0 -g -Wall -pedantic -std=c99 #Using c99 is recommended on Linux, but this works better on OSX
LDFLAGS = -pthread
output = clackjack
objects = player.o cards.o game.o ai.o main.o

clackjack: $(objects)
	$(CC)  $(CFLAGS) $(LDFLAGS) -o$(output) $(objects)

main.o:
player.o:
cards.o:
game.o:
ai.o:


clean:
	rm -f $(output) *.o
