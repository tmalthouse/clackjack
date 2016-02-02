#ifndef CLACKJACK_PLAYER_H
#define CLACKJACK_PLAYER_H
#include "game.h"

bool get_input_stdin (Game game);
void disp_output_stdout (Game *game, enum SITUATIONS situation);
void init();

void *player_game(void *id);


#endif /* end of include guard: CLACKJACK_PLAYER_H */
