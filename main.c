#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "cards.h"
#include "game.h"

void startgame();

int main() {
  srand(time(NULL));
  startgame();
}

void startgame() {
  bool hold = false;

  Game current_game = new_game();
  printf("Your initial total is %d\n", current_game.sum);

  while (current_game.sum<21 && !hold) {
    char ans;

    list_cards(current_game);

    printf("Draw another card? (y/n)\n");

    //Wait for input (that's not \n)
    while ((ans = getchar()) == '\n');

    if (ans == 'n') {
      hold = true;
    }
    else if (ans == 'y') {
      add_card(&current_game);
      update(&current_game);
      printf("\n\nYour new total is %d\n",current_game.sum);
    }
    else {
      printf("You didn't do that right, pal\n");
    }
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
