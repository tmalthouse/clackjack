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
  int next_card, num;
  bool hold = false;

  next_card = 0;
  num = 2;

  add_card(hand, &next_card);
  add_card(hand, &next_card);
  printf("Your initial total is %d\n", sum_cards(num, hand));;

  while (sum_cards(num,hand)<21 && !hold) {
    char ans;

    list_cards(hand, num);

    printf("Draw another card? (y/n)\n");

    //Wait for input (that's not \n)
    while ((ans = getchar()) == '\n');

    if (ans == 'n') {
      hold = true;
    }
    else if (ans == 'y') {
      add_card(hand, &next_card);
      num+=1;
      printf("\n\nYour new total is %d\n", sum_cards(num,hand));
    }
    else {
      printf("You didn't do that right, pal\n");
    }
  }
  if (sum_cards(num,hand)>21) {
    printf("You went over! Better luck next time\n");
  } else {
    printf("You held!\n");
  }
  list_cards(hand,num);

  return;
}
