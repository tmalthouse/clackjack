cc = /usr/bin/c99
cflags = -O2 -Wall
output = dealer

dealer:
	$(cc) dealer.c main.c cards.c game.c $(cflags) -o$(output)

clean:
	rm $(output)
