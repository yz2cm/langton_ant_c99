#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "matrix.h"
#include "black_point_list.h"
#include "matrix_line_list.h"
#include "play.h"

void write_symbols(const matrix_line_t *a_line);

int main (void) {
    black_point_list_t *result = play(20000);
    matrix_t *matrix = black_point_list_to_matrix(result);
    size_t width = black_point_list_width(result);
    matrix_line_list_t *line_list = matrix_split(matrix, width);
    matrix_line_list_map(line_list, write_symbols);

    return 0;
}

void write_symbols(const matrix_line_t *a_line) {
    char *line = malloc(a_line->length * sizeof(*line) + 1);
    colors_to_symbols(line, a_line->colors, a_line->length);
    line[a_line->length] = '\0';

    printf("%s\n", line);

    free(line);
}
