#include "game.h"
#include "cards.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


Game new_game () {
  Game game={};
  add_card(&game);
  add_card(&game);
  sum(&game);
  return game;
}

void sum (Game *game) {
  game->sum=sum_cards(game->next_card, game->cards);
}

void update(Game *game) {
  sum(game);
}

void add_card (Game *game) {
  //printf("%d\n", game->next_card);
  game->cards[game->next_card] = draw_card();
  game->next_card+=1;
  return;
}

void list_cards(Game game) {
  //List the current cards
  printf("Your cards are:\n");
  for (int i=0;i<game.next_card;i++) {
    disp_card(game.cards[i]);
  }
  return;
}
