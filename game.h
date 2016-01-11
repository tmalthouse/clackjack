#ifndef CLACKJACK_GAME_H
#define CLACKJACK_GAME_H


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

enum SITUATIONS {
  INITIAL_TOTAL,
  LOOP_TOTAL,
  END
};

Game* new_game();
Game* run_game (char(*inputfn)(Game game), void(*outputfn)(Game *game, enum SITUATIONS situation));
void add_card(Game *game);
void sum (Game *game);
void list_cards (Game game);
void update (Game *game);
void gameloop (Game *game, char(*inputfn)(Game game), void(*outputfn)(Game *game, enum SITUATIONS situation));
Game compare_games(Game g1, Game g2);

#endif /* end of include guard: CLACKJACK_GAME_H */
