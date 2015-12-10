cc = /usr/bin/c99
cflags = -O2 -Wall
output = dealer

dealer:
	$(cc) dealer.c cards.c $(cflags) -o$(output)

clean:
	rm $(output)
