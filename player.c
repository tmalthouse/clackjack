#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "cards.h"
#include "game.h"
#include "player.h"

Game player_game();


int main () {
  player_game();
}

Game player_game () {
  init();
  char(*inputfn)(Game) = get_input_stdin;
  void(*outputfn)(Game*, enum SITUATIONS) = disp_output_stdout;
  run_game (inputfn, outputfn);

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
      printf("Your total is %d.\n", game->sum);
      list_cards(*game);
      break;
    case LOOP_TOTAL:
      list_cards(*game);
      printf("Your total is %d.\n", game->sum);
      printf("Draw another card? (y/n)");
      break;
    case END:
      printf("Your final total was %d.\n", game->sum);
      if (game->sum > 21) {
        printf("You went over!\n");
      } else if (game->hold) {
        printf("You held!");
      } else {
        printf("Perfect blacjack!\n");
      }
      break;

  }
}

void init() {
  srand(time(NULL));
}
