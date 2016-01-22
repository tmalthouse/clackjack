#include <pthread.h>
#include <stdio.h>
#include "player.h"
#include "ai.h"


volatile int current_player;
int num_players;

int main (int argc, char** argv) {
  int id_list[15];
  void *(*gametypes[10]) (void *id) = {NULL}; // Make an array of pointers to game type functions

  for (int i=0;i<15;i++) {
    id_list[i]=i;
  }

  gametypes[0] = player_game;
  gametypes[1] = ai_game;

  pthread_t tid_list[15];
  Game *finished_games[15];
  for (int i=0;gametypes[i]!=NULL;i++) { //Create a thread for each function in the given array
    pthread_create(&tid_list[i], NULL, gametypes[i], &id_list[i]);
    num_players++;
  }

  for (int i=0;i<num_players;i++) { //Once the threads are done, bind their returns to the fin_games array
    pthread_join(tid_list[i], (void**)&finished_games[i]);
  }


}

void next_player () {
  if (current_player < (num_players-1)) {
    current_player++;
  } else {
    current_player = 0;
  }
}
