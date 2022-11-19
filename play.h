#ifndef __YZ2CM_LANGTON_ANT_PLAY_H__
#define __YZ2CM_LANGTON_ANT_PLAY_H__
#include "common.h"

ant_t               play_once(ant_t ant, black_point_list_t *list);
black_point_list_t *play(uint32_t step);

#endif
