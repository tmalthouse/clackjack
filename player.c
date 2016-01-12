#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "cards.h"
#include "game.h"
#include "player.h"
/*
int main () {
  player_game();
}*/

Game* player_game () {
  init();
  char(*inputfn)(Game) = get_input_stdin;
  void(*outputfn)(Game*, enum SITUATIONS) = disp_output_stdout;
  return run_game (inputfn, outputfn);
}

char get_input_stdin (Game game) {
  char ans;
  while ((ans = getchar()) == '\n');
  return ans;
}

void disp_output_stdout (Game *game, enum SITUATIONS situation) {
  switch (situation) {
    case INITIAL_TOTAL:
      printf("Welcome to clackjack!\n");
      printf("Your initial total is %d.\n", game->sum);
      list_cards(*game);
      printf("Draw another card? (y/n)\n");
      break;

    case LOOP_TOTAL:
      printf("\n\n\nYour total is %d.\n", game->sum);
      list_cards(*game);
      if (game->sum<21) {
        printf("Draw another card? (y/n)\n");
      }
      break;

    case END:
      printf("\n\nYour final total was %d.\n", game->sum);
      if (game->sum > 21) {
        printf("You went over!\n");
      } else if (game->hold) {
        printf("You held!");
      } else {
        printf("Perfect blacjack!\n");
      }
      break;

    case ERR:
      printf("Something's gone wrong!!!\n");
      break;

  }
}

void init() {
  srand(time(NULL));
}
