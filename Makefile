CC = gcc
cflags = -O2 -Wall -pedantic
output = clackjack
objects = dealer.o main.o cards.o game.o

clackjack: $(objects)
	$(CC)  $(cflags) -o$(output) $(objects)

dealer.o:
main.o:
cards.o:
game.o:


clean:
	rm $(output) *.o
