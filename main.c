#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "cards.h"

void startgame();
void add_card(Card *cardlist, int *pos);

int main() {
  srand(time(NULL));
  startgame();
}

void add_card (Card *cardlist, int *pos) {
  cardlist[*pos] = draw_card();
  *pos+=1;
  return;
}

void startgame() {
  Card hand[21]; //We'll never need more cards than this
  int next_card, sum;
  bool hold = false;

  next_card = 0;
  sum = 2;

  add_card(hand, &next_card);
  add_card(hand, &next_card);
  printf("Your initial total is %d\n", sum_cards(sum, hand));;

  while (sum_cards(sum,hand)<21 && !hold) {
    char ans;
    printf("Draw another card? (y/n)\n");

    while ((ans = getchar()) == '\n');

    if (ans == 'n') {
      hold = true;
    }
    else if (ans == 'y') {
      add_card(hand, &next_card);
      sum+=1;
      printf("Your new total is %d\n", sum_cards(sum,hand));
    }
    else {
      printf("You didn't do that right, pal\n");
    }
  }

  printf("THis is the end of the loop\n" );
  return;
}
