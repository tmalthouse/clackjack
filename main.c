#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "player.h"
#include "ai.h"


volatile int current_player;
volatile int finished_num;
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
  Game *finished_games[15] = {NULL};
  for (int i=0;gametypes[i]!=NULL;i++) { //Create a thread for each function in the given array
    pthread_create(&tid_list[i], NULL, gametypes[i], &id_list[i]);
    num_players++;
  }

  for (int i=0;i<num_players;i++) { //Once the threads are done, bind their returns to the fin_games array
    int err = pthread_join(tid_list[i], (void**)&finished_games[i]);
    //printf("Joined thread %d\n", i);
    if (err) {//If one of the threads can't return, print an error and die
      fprintf(stderr, "Error returning from thread %d: %s\n",i,strerror(err));
      exit(EXIT_FAILURE);
    }
  }

  Game *winner = compare_games (finished_games[0],finished_games[1]);
  if (winner==NULL) {
    printf ("Everyone went over! Nobody wins.\n");
  } else {
    printf ("The winner was %s, with a score of %d!\n",winner->name,winner->sum);
  }

  for (int i=0;finished_games[i]!=NULL;i++) {
    //printf("Freeing %d\n", i);
    free(finished_games[i]);
  }
}

void next_player () {
  if (current_player < (num_players-1)) {
    current_player++;
  } else {
    current_player = 0;
  }
}
