CC = c99
cflags = -O2 -Wall -pedantic
output = clackjack
objects = player.o cards.o game.o ai.o

clackjack: $(objects)
	$(CC)  $(cflags) -o$(output) $(objects)

player.o:
cards.o:
game.o:
ai.o:


clean:
	rm $(output) *.o
