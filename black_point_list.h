#ifndef __YZ2CM_LANGTON_ANT_BLACK_POINT_LIST_H__
#define __YZ2CM_LANGTON_ANT_BLACK_POINT_LIST_H__
#include "common.h"

black_point_list_t *black_point_list_new(void);
point_t            *black_point_list_find(const black_point_list_t *list, point_t point);
bool                black_point_list_contains(const black_point_list_t *list, point_t point);
void                black_point_list_add(black_point_list_t *list, point_t point);
void                black_point_list_remove(const black_point_list_t *list, point_t point);
int32_t             black_point_list_max_x(const black_point_list_t *list);
int32_t             black_point_list_min_x(const black_point_list_t *list);
int32_t             black_point_list_max_y(const black_point_list_t *list);
int32_t             black_point_list_min_y(const black_point_list_t *list);
size_t              black_point_list_width(const black_point_list_t *list);
size_t              black_point_list_height(const black_point_list_t *list);

#endif
