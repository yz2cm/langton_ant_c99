#include <stdlib.h>
#include "matrix.h"
#include "common.h"

matrix_t *matrix_new() {
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
    if (matrix->colors == NULL || matrix->capacity < capacity_needs) {
        matrix->colors = realloc(matrix->colors, capacity_needs * 2);
        matrix->capacity = capacity_needs * 2;
    }

    matrix->colors[matrix->length] = a_color;
    matrix->length++;
}

matrix_line_list_t *matrix_line_list_new() {
    matrix_line_list_t *line_list = malloc(sizeof(*line_list));
    line_list->lines = NULL;
    line_list->length = 0;

    return line_list;
}

void matrix_line_list_add(matrix_line_list_t *line_list, const cell_color_t *colors, size_t length) {
    line_list->lines = realloc(line_list->lines, (line_list->length + 1) * sizeof(*(line_list->lines)));
    (line_list->lines + line_list->length)->colors = colors;
    (line_list->lines + line_list->length)->length = length;
    line_list->length++;
}

matrix_line_list_t *matrix_split(const matrix_t *matrix, size_t width) {
    matrix_line_list_t *line_list = matrix_line_list_new();

    for (size_t i = 0; i < matrix->length; i += width) {
        size_t width_ = (i + width) < matrix->length ? width : matrix->length - i;
        matrix_line_list_add(line_list, matrix->colors + i, width_);
    }

    return line_list;
}

void matrix_line_list_map(const matrix_line_list_t *line_list, void (*call_back)(const matrix_line_t *)) {
    for (size_t i = 0; i < line_list->length ; ++i) {
        matrix_line_t *a_line = line_list->lines + i;
        call_back(a_line);
    }
}
