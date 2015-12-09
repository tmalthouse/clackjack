#include "cards.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* PROTOTYPES*/

struct Card draw_card ();
int sum_cards (int, Card*);
bool isRed(Card);

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

int sum_cards (int numcards, Card* cardlist) {
  int sum = 0;
  for (int i=0;i<numcards;i++) {
    sum += cardlist[i].value+1;
    printf("Current sum is %d\n",sum);
  }
  return sum;
}

bool is_red(Card card) {
  if (card.suit == HEARTS || card.suit == DIAMONDS) {
    return true;
  } else {
    return false;
  }
}

int main() {
  Card hand[10];

  for (int i=0;i<10;i++) {
    hand[i] = draw_card();
    printf("Card %d's value is %d and its suit is %d\n",i,hand[i].value,hand[i].suit );
  }


  printf("The total of the ten cards is %d!\n", sum_cards(10, hand));
  return 1;
}
