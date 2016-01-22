CC = c99
CFLAGS = -O0 -g -Wall -pedantic
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
