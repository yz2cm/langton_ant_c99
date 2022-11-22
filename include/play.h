#ifndef __YZ2CM_LANGTON_ANT_PLAY_H__
#define __YZ2CM_LANGTON_ANT_PLAY_H__
#include "common.h"


black_point_list_t  *play(uint32_t step);
ant_t                play_ant_on_black(const ant_t *ant, black_point_list_t *list);
ant_t                play_ant_on_white(const ant_t *ant, black_point_list_t *list);
black_point_list_t  *play_automaton(uint32_t step);

#endif
