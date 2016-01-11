#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "game.h"
#include "cards.h"
#include "ai.h"

Game ai_game () {
  srand(time(NULL));
  char (*inputfn)(Game) = get_input_robot;

  Game current_game = new_game();

  while (current_game.sum<21 && !current_game.hold) {
    gameloop(&current_game, inputfn);
  }
  return current_game;
}


  char get_input_robot (Game game) {
    return 'y';
  }
