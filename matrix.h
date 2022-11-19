#ifndef __YZ2CM_LANGTON_ANT_MATRIX_H__
#define __YZ2CM_LANGTON_ANT_MATRIX_H__
#include <stddef.h>
#include "common.h"

matrix_t *matrix_new();
void matrix_add_cell(matrix_t *matrix, cell_color_t a_color);
matrix_line_list_t *matrix_line_list_new();
void matrix_line_list_add(matrix_line_list_t *line_list, const cell_color_t *colors, size_t length);
matrix_line_list_t *matrix_split(const matrix_t *matrix, size_t width);
void matrix_line_list_map(const matrix_line_list_t *line_list, void (*call_back)(const matrix_line_t *));

#endif
