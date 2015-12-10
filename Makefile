$CC=/usr/bin/c99
$CFLAGS="-O1 -Wall"
$OUT="dealer"

dealer:
	c99 dealer.c -O1 -Wall -odealer

clean:
	rm $OUT
