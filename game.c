#include "game.h"
#include "cards.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


Game new_game() {
  Game game={};
  add_card(game.cards, &(game.next_card));
  add_card(game.cards, &(game.next_card));
  game.sum=sum_cards(game.next_card, game.cards);
  return game;
}

void add_card (Card *cardlist, int *pos) {
  cardlist[*pos] = draw_card();
  *pos+=1;
  return;
}
