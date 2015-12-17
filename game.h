#ifndef GAME
#define  GAME GAME
#include "cards.h"
#include <stdbool.h>


void add_card(Card *cardlist, int *pos);

typedef struct Game Game;

struct Game {
  Card cards[21];
  int sum;
  int turn;
  int next_card;
  bool hold;
};

#endif
