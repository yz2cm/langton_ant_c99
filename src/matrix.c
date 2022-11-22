#include <stdlib.h>
#include <string.h>
#include "../include/matrix.h"
#include "../include/common.h"
#include "../include/matrix_line_list.h"
#include "../include/black_point_list.h"

matrix_t *matrix_new(size_t width, size_t height) {
    matrix_t *matrix = malloc(sizeof(*matrix));
    {
        matrix->width = width;
        matrix->height = height;
        size_t capacity = height * width * sizeof(*(matrix->colors));
        matrix->colors = malloc(capacity);
        memset(matrix->colors, (int)WHITE, capacity);
    }

    return matrix;
}

size_t matrix_length(const matrix_t *matrix) {
    return matrix->height * matrix->width;
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
    const size_t matrix_len = matrix_length(matrix);

    for (size_t i = 0; i < matrix_len; i += matrix->width) {
        const cell_color_t *colors = matrix->colors + i;
        const size_t colors_length = matrix->width <= (matrix_len - i) ? matrix->width : (matrix_len - i);
        matrix_line_list_add(line_list, colors, colors_length);
    }

    return line_list;
}

matrix_t* matrix_from(const black_point_list_t *list) {

    matrix_t *matrix;
    {
        const point_t max = point_new_noheap(black_point_list_max_x(list), black_point_list_max_y(list));
        const point_t min = point_new_noheap(black_point_list_min_x(list), black_point_list_min_y(list));
        const size_t width =  (size_t)max.x - (size_t)min.x + 1;
        const size_t height = (size_t)max.y - (size_t)min.y + 1;
        matrix = matrix_new(width, height);
    }

    matrix_plot_points(matrix, list, BLACK);

    return matrix;
}

void matrix_plot_points(matrix_t *matrix, const black_point_list_t *list, cell_color_t color) {

    for (size_t i = 0; i < list->length; ++i) {
        if (! list->points[i].used) {
            continue;
        }
        matrix_set_cell(matrix, (size_t)list->points[i].x, (size_t)list->points[i].y, color);
    }
}