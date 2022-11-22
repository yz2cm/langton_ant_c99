#include <stdio.h>
#include <stdlib.h>
#include "include/common.h"
#include "include/matrix.h"
#include "include/black_point_list.h"
#include "include/matrix_line_list.h"
#include "include/play.h"

void write_symbols(const matrix_line_t *a_line);

int main (void) {
    #ifdef __AUTOMATON__
    const black_point_list_t *result = play_automaton(20000);
    #else
    const black_point_list_t *result = play(20000);
    #endif
    const matrix_t *matrix = matrix_from(result);
    const matrix_line_list_t *line_list = matrix_split(matrix);

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
