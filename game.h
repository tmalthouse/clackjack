#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H


#include "cards.h"
#include <stdbool.h>

typedef struct Game Game;

struct Game {
  Card cards[21];
  int sum;
  int turn;
  int next_card;
  bool hold;
};

Game new_game();
void add_card(Game *game);
void sum (Game *game);
void list_cards (Game game);
void update (Game *game);
void gameloop (Game *game, bool hold);

#endif /* end of include guard: BLACKJACK_GAME_H */
