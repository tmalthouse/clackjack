#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
    //printf("Current sum is %d\n",sum);
  }
  return sum;
}



struct Card draw_card () {
  enum Suit current_suit;
  switch (rand()%4) {
    case 0:
      current_suit = HEARTS;
      break;
    case 1:
      current_suit = DIAMONDS;
      break;
    case 2:
      current_suit = SPADES;
      break;
    case 3:
      current_suit = CLUBS;
      break;
    default:
      printf("Something went wrong in the suit picker!!\nWe're making it a clubs anyway\n");
      current_suit = CLUBS;
      break;
  }
  Card current_card = {current_suit, (char)(rand()%13)};
  return current_card;
}
