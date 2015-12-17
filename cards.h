#include <stdbool.h>
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

struct Card draw_card ();
int sum_cards (int numcards, Card* cardlist);
bool isRed(Card card);

const char* get_value (Card card);
const char* get_suit (Card card);

void disp_card(Card card);
void list_cards(Card* hand, int num);

#endif
