#include "game.h"
#include "cards.h"
#ifndef AI_CLACKJACK
#define AI_CLACKJACK

char get_input_robot (Game game);
void robot_output (Game *game, enum SITUATIONS situ);
void *ai_game (void *id);

#endif /* end of include guard: AI_CLACKJACK */
