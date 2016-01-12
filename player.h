#ifndef CLACKJACK_PLAYER_H
#define CLACKJACK_PLAYER_H
#include "game.h"

char get_input_stdin (Game game);
void disp_output_stdout (Game *game, enum SITUATIONS situation);
void init();

Game* player_game();


#endif /* end of include guard: CLACKJACK_PLAYER_H */
