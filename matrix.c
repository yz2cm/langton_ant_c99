#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "common.h"

matrix_t *matrix_new() {
    matrix_t *matrix = malloc(sizeof(*matrix));
    matrix->color = NULL;
    matrix->length = 0;
    matrix->capacity = 0;

    return matrix;
}

void matrix_add_cell(matrix_t *matrix, cell_color_t color) {
    if (matrix == NULL) {
        return;
    }

    size_t capacity_needs = (matrix->length + 1) * sizeof(*(matrix->color));
    if (matrix->color == NULL || matrix->capacity < capacity_needs) {
        matrix->color = realloc(matrix->color, capacity_needs * 2);
        matrix->capacity = capacity_needs * 2;
    }

    matrix->color[matrix->length] = color;
    matrix->length++;
}

void matrix_print(size_t width, const matrix_t *matrix) {
    for (size_t length = 0; length < matrix->length; ++length) {
        cell_color_t color = matrix->color[length];
        printf("%c", color_to_symbol(color));

        if(length != 0 && length % width == (width - 1)) {
            printf("\n");
        }
    }
}
