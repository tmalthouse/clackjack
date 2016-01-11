CC = c99
cflags = -O2 -Wall -pedantic
output = clackjack
objects = main.o cards.o game.o ai.o

clackjack: $(objects)
	$(CC)  $(cflags) -o$(output) $(objects)

main.o: cards.h game.h
cards.o: cards.h
game.o: cards.h game.h
ai.o: game.h cards.h ai.h


clean:
	rm $(output) *.o
