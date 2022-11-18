#ifndef __YZ2CM_LANGTON_ANT_ANT_H__
#define __YZ2CM_LANGTON_ANT_ANT_H__
#include "common.h"

ant_t ant_new();
ant_t move_forward_ant(const ant_t* ant);
ant_t rotate_right_ant(const ant_t* ant);
ant_t rotate_left_ant(const ant_t* ant);

#endif
