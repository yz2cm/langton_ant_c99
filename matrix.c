#include <stdlib.h>
#include "matrix.h"
#include "common.h"
#include "matrix_line_list.h"

matrix_t *matrix_new(void) {
    matrix_t *matrix = malloc(sizeof(*matrix));
    matrix->colors = NULL;
    matrix->length = 0;
    matrix->capacity = 0;

    return matrix;
}

void matrix_add_cell(matrix_t *matrix, cell_color_t a_color) {
    if (matrix == NULL) {
        return;
    }

    size_t capacity_needs = (matrix->length + 1) * sizeof(*(matrix->colors));
    if (matrix->capacity < capacity_needs) {
        matrix->colors = realloc(matrix->colors, capacity_needs * 2);
        matrix->capacity = capacity_needs * 2;
    }

    matrix->colors[matrix->length] = a_color;
    matrix->length++;
}

matrix_line_list_t *matrix_split(const matrix_t *matrix, size_t width) {
    matrix_line_list_t *line_list = matrix_line_list_new();

    for (size_t i = 0; i < matrix->length; i += width) {
        size_t width_ = (i + width) < matrix->length ? width : matrix->length - i;
        matrix_line_list_add(line_list, matrix->colors + i, width_);
    }

    return line_list;
}
