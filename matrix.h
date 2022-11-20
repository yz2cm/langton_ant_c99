#ifndef __YZ2CM_LANGTON_ANT_MATRIX_H__
#define __YZ2CM_LANGTON_ANT_MATRIX_H__
#include <stddef.h>
#include "common.h"

matrix_t           *matrix_new(size_t width, size_t height);
void                matrix_fill_with(matrix_t *matrix, cell_color_t color);
void                matrix_set_cell(matrix_t *matrix, size_t x, size_t y, cell_color_t color);
matrix_line_list_t *matrix_split(const matrix_t *matrix);
matrix_t*           matrix_from(const black_point_list_t *list);
void                matrix_plot_points(matrix_t *matrix, const black_point_list_t *list, cell_color_t color);

#endif
