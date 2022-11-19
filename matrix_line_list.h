#ifndef __YZ2CM_LANGTON_ANT_MATRIX_LINE_LIST_H__
#define __YZ2CM_LANGTON_ANT_MATRIX_LINE_LIST_H__
#include <stddef.h>
#include "common.h"

matrix_line_list_t *matrix_line_list_new();
void                matrix_line_list_add(matrix_line_list_t *line_list, const cell_color_t *colors, size_t length);
void                matrix_line_list_map(const matrix_line_list_t *line_list, void (*call_back)(const matrix_line_t *));

#endif
