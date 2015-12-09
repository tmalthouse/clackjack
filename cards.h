#ifndef CARDS
#define  CARDS

enum Suit {
  HEARTS,
  SPADES,
  CLUBS,
  DIAMONDS
};

typedef struct Card Card;

struct Card {
  enum Suit suit;
  char value; //1 is aces, 2-10 are normal, 11 is jack, etc.
};

#endif
