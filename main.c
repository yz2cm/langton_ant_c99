#include <stdio.h>
#include "common.h"
#include "matrix.h"
#include "black_point_list.h"
#include "play.h"

void write_symbol(cell_color_t *colors, size_t length) {
    for(size_t i = 0; i < length; ++i) {
        printf("%c", color_to_symbol(colors[i]));
    }
    printf("\n");
}

int main (void) {
    black_point_list_t *result = play(20000);
    matrix_t *matrix = black_points_to_matrix(result);
    size_t width = width_of_black_point_list(result);
    matrix_map(matrix, width, write_symbol);

    return 0;
}
