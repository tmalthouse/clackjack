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

const char* get_suit (Card card) {
  int suit = card.suit;
  const char* ans;
  if (suit==CLUBS) {
    ans = "clubs";
  }
  else if (suit==DIAMONDS) {
    ans = "diamonds";
  }
  else if(suit==SPADES) {
    ans = "spades";
  }
  else {
    ans = "hearts";
  }
  return ans;
}

const char* get_value (Card card) {
  int val = card.value;
  const char* CARD_NAMES[13] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
  return CARD_NAMES[val];
}
