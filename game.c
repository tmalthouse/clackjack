#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "globals.h"
#include "main.h"
#include "game.h"
#include "cards.h"

Game* run_game (bool(*inputfn)(Game game), void(*outputfn)(Game *game, enum SITUATIONS situation), int id, char *name) {
  srand(time(NULL));//Set a random seed for the cards.
  Game *current_game = new_game();
  (*outputfn)(current_game, INITIAL_TOTAL);
  strcpy(current_game->name, name);

  while (current_game->sum<21 && !current_game->hold) {
    gameloop(current_game, inputfn, outputfn, id);
  }
  (*outputfn)(current_game, END);
  finished_num++;
  while (finished_num < num_players) {
    if (current_player == id) {
      next_player();
    }
  }
  return current_game;
}

Game* new_game () {
  Game *game=(Game*)malloc(sizeof(Game));
  add_card(game);
  add_card(game);
  update(game);
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

Game *compare_games (Game *g1, Game *g2) {
  Game *winner;

  if (g1->sum > 21 && g2->sum > 21) {
    winner = NULL;
  } else if ((g1->sum > 21) ^ (g2->sum > 21)) { //Bitwise xor
    winner = (g1->sum > g2->sum) ? g2 : g1; //Otherwise the one who didn't go over wins
  } else if (g1->sum == g2->sum) {
    if (g1->next_card == g2->next_card) {
      winner = g1; //This is such a rare tie anyways
    } else {
      winner = (g1->next_card < g2->next_card) ? g1 : g2; //Return the lower count
    }
  } else {
    winner = (g1->sum > g2->sum) ? g1 : g2; // Return the higher sum
  }

  return winner;
}



void gameloop (Game *game, bool(*inputfn)(Game game), void(*outputfn)(Game *game, enum SITUATIONS situ), int id) {
  char ans;

  //(*outputfn)(game, INITIAL_TOTAL);

  //Wait for input, based off the passed function pointer (this lets us change how input is recieved)
  while (current_player!=id);
  ans = (*inputfn)(*game);

  //printf("preinput for %d\n", id);
  if (ans == false) {
    game->hold = true;
  }
  else if (ans == true) {
    add_card(game);
    update(game);
    (*outputfn)(game, LOOP_TOTAL);
  }
  else {
    (*outputfn)(game, ERR);
  }
  next_player();
}
