#ifndef __YZ2CM_LANGTON_ANT_BLACK_POINT_LIST_H__
#define __YZ2CM_LANGTON_ANT_BLACK_POINT_LIST_H__
#include "common.h"

black_point_list_t *black_point_list_new();
point_t *black_point_list_find_unused(const black_point_list_t *list, point_t point);
point_t *black_point_list_find(const black_point_list_t *list, point_t point);
void black_point_list_add(black_point_list_t *list, point_t point);
void black_point_list_remove(const black_point_list_t *list, point_t point);
int32_t max_x_of_black_points(const black_point_list_t *list);
int32_t min_x_of_black_points(const black_point_list_t *list);
int32_t max_y_of_black_points(const black_point_list_t *list);
int32_t min_y_of_black_points(const black_point_list_t *list);
size_t width_of_black_point_list(black_point_list_t *list);
matrix_t *black_points_to_matrix(const black_point_list_t *list);

#endif
