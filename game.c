#include "game.h"
#include "cards.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


Game new_game () {
  Game game={};
  add_card(&game);
  add_card(&game);
  update(&game);
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
}

void list_cards(Game game) {
  printf("Your cards are:\n");
  for (int i=0;i<game.next_card;i++) {
    display_card(game.cards[i]);
  }
}

void gameloop (Game *game, bool hold) {
  char ans;

  list_cards(*game);

  printf("Draw another card? (y/n)\n");

  //Wait for input (that's not \n)
  while ((ans = getchar()) == '\n');

  if (ans == 'n') {
    hold = true;
  }
  else if (ans == 'y') {
    add_card(game);
    update(game);
    printf("\n\nYour new total is %d\n",game->sum);
  }
  else {
    printf("You didn't do that right, pal\n");
  }
}
