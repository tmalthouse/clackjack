#include <stdlib.h>
#include <time.h>
#include "cards.h"

void startgame();
void add_card(Card *cardlist, int pos);

int main() {
  srand(time(NULL));
  startgame();
}

void add_card (Card *cardlist, int pos) {
  cardlist[pos] = draw_card();
  return;
}

void startgame() {
  Card hand[21]; //We'll never need more cards than this
  int next_card, sum;
  while (sum<21) {

  }
}
