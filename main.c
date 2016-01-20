#include <pthread.h>
#include <stdio.h>
#include "player.h"
#include "ai.h"
#include "globals.h"

volatile int current_player;
int num_players;

int main (int argc, char** argv) {
  int *id_list[15];
  int next_id = 0;
  void *(*gametypes[10]) (void *id) = {NULL}; // Make an array of pointers to game type functions

  gametypes[0] = player_game;
  gametypes[1] = ai_game;

  pthread_t tid_list[15];
  for (int i=0;i<15;i++) { //Create a thread for each function in the given array
    if (gametypes[i] != NULL) {
      printf("Thread created with id %d\n", next_id);
      pthread_create(&tid_list[next_id], NULL, gametypes[i], &id_list[next_id]);
      next_id++;
    } else { //The pointers are consecutive -- we can break on the 1st NULL
      printf("No ID found in position %d! Stopping thread creation!\n", i);
      break;
    }
  }
  num_players = 2;
  for (;;);
}

void next_player () {
  if (current_player < (num_players-1)) {
    current_player++;
  } else {
    current_player = 0;
  }
}
