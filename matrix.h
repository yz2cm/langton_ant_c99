#ifndef __YZ2CM_LANGTON_ANT_MATRIX_H__
#define __YZ2CM_LANGTON_ANT_MATRIX_H__
#include <stddef.h>
#include "common.h"

matrix_t *matrix_new();
void matrix_add_cell(matrix_t *matrix, cell_color_t color);
void matrix_print(size_t width, const matrix_t *matrix);

#endif
