#include <stdlib.h>
#include "common.h"
#include "matrix_line_list.h"

matrix_line_list_t *matrix_line_list_new(void) {
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

void matrix_line_list_map(const matrix_line_list_t *line_list, void (*call_back)(const matrix_line_t *)) {
    for (size_t i = 0; i < line_list->length ; ++i) {
        matrix_line_t *a_line = line_list->lines + i;
        call_back(a_line);
    }
}
