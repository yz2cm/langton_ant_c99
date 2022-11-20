#include <stdlib.h>
#include "matrix.h"
#include "common.h"
#include "matrix_line_list.h"
#include "black_point_list.h"

matrix_t *matrix_new(size_t width, size_t height) {
    matrix_t *matrix = malloc(sizeof(*matrix));
    {
        matrix->width = width;
        matrix->height = height;
        matrix->length = width * height;
        matrix->capacity = matrix->length * sizeof(*(matrix->colors));
        matrix->colors = malloc(matrix->capacity);
    }

    return matrix;
}

void matrix_set_cell(matrix_t *matrix, size_t x, size_t y, cell_color_t color) {
    if (matrix == NULL) {
        return;
    }
    
    if (matrix->width <= x || matrix->height <= y) {
        return;
    }

    matrix->colors[y * matrix->width + x] = color;
}

matrix_line_list_t *matrix_split(const matrix_t *matrix) {
    matrix_line_list_t *line_list = matrix_line_list_new();

    for (size_t i = 0; i < matrix->length; i += matrix->width) {
        const cell_color_t *colors = matrix->colors + i;
        const size_t colors_length = matrix->width <= (matrix->length - i) ? matrix->width : (matrix->length - i);
        matrix_line_list_add(line_list, colors, colors_length);
    }

    return line_list;
}

matrix_t* matrix_from(const black_point_list_t *list) {

    const point_t max = point_new_noheap(black_point_list_max_x(list), black_point_list_max_y(list));
    const point_t min = point_new_noheap(black_point_list_min_x(list), black_point_list_min_y(list));

    matrix_t *matrix;
    {
        const size_t width =  (size_t)max.x - (size_t)min.x + 1;
        const size_t height = (size_t)max.y - (size_t)min.y + 1;
        matrix = matrix_new(width, height);
    }

    for(int32_t y = min.y; y <= max.y; ++y) {
        for(int32_t x = min.x; x <= max.x; ++x) {
            const size_t offset_x = (size_t)x - (size_t)min.x;
            const size_t offset_y = (size_t)y - (size_t)min.y;

            if (black_point_list_contains(list, point_new_noheap(x, y))) {
                matrix_set_cell(matrix, offset_x, offset_y, BLACK);
            } else {
                matrix_set_cell(matrix, offset_x, offset_y, WHITE);
            }
        }
    }

    return matrix;
}

