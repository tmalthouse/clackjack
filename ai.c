#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "game.h"
#include "cards.h"
#include "ai.h"
#include "globals.h"

void *ai_game (void* id) {
  int game_id = *(int*)id;
  char(*inputfn)(Game) = get_input_robot;
  void(*outputfn)(Game*, enum SITUATIONS) = robot_output;

  char name[20];
  strcpy(name, "the dealer");

  return run_game (inputfn, outputfn, game_id, name);
}

char get_input_robot (Game game) {
  if (game.sum<=17) { //super simple ai -- hit on <=17
    return 'y';
  } else {
    return 'n';
  }
}

void robot_output (Game *game, enum SITUATIONS situ) {
  switch (situ) {
    case INITIAL_TOTAL:
      break;
    case LOOP_TOTAL:
      printf("The dealer has %d cards.\n\n",game->next_card);
      break;
    case END:
      printf("The dealer held.\n\n");
      break;
    case ERR:
      fprintf(stderr,"Something went wrong!\n");
      exit(1);
      break;
  }
  return;
}
