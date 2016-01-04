#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "cards.h"
#include "game.h"

void startgame();

int main () {

  startgame();
}

void startgame () {
  srand(time(NULL));
  bool hold = false;

  Game current_game = new_game();
  printf("Your initial total is %d\n", current_game.sum);

  while (current_game.sum<21 && !hold) {
    gameloop(&current_game, hold);
  }

  if (current_game.sum>21) {
    printf("You went over! Better luck next time\n");
  } else if (hold){
    printf("You held!\n");
  } else {
    printf("Perfect blackjack!\n");
  }
  list_cards(current_game);
}
