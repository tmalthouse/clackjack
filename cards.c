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
  int ace = 0;

  for (int i=0;i<numcards;i++) { //All face cards are 10
    if (cardlist[i].value>=10) {
      sum += 10;
    }
    else if (cardlist[i].value==0) { //Assume aces are 11 unless they go over
      ace+=1;
      sum+=11;
    }
    else { //Everything else is just face value (+0 indexing)
      sum += cardlist[i].value+1;
    }
  }

  while (ace && sum>21) { //Turn soft 11s into 1s until we're below 21
    sum -=10;
    ace -=1;
  }

  return sum;
}

struct Card draw_card () {
  enum Suit current_suit;
  current_suit = rand()%4;
  Card current_card = {current_suit, (char)(rand()%13)};
  return current_card;
}

const char* get_suit (Card card) {
  int suit = card.suit;
  const char* SUITS[] = {"hearts","spades","clubs","diamonds"};
  return SUITS[suit];
}

const char* get_value (Card card) {
  int val = card.value;
  const char* CARD_NAMES[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
  return CARD_NAMES[val];
}

void disp_card(Card card) { //TODO:0 Add Ncurses based renderer
  printf("%s of %s\n",get_value(card), get_suit(card));
  return;
}
