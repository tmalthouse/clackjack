#include <stdio.h>
#include "cards.h"

bool is_red(Card card) {
  if (card.suit == HEARTS || card.suit == DIAMONDS) {
    return true;
  } else {
    return false;
  }
}

int sum_cards (int numcards, Card* cardlist) {
  int sum = 0;
  for (int i=0;i<numcards;i++) {
    sum += cardlist[i].value+1;
    printf("Current sum is %d\n",sum);
  }
  return sum;
}
