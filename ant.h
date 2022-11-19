#ifndef __YZ2CM_LANGTON_ANT_ANT_H__
#define __YZ2CM_LANGTON_ANT_ANT_H__
#include "common.h"

ant_t ant_new();
ant_t ant_move_forward(const ant_t* ant);
ant_t ant_rotate_right(const ant_t* ant);
ant_t ant_rotate_left(const ant_t* ant);

#endif
