#include "common.h"
#include "matrix.h"
#include "black_point_list.h"
#include "play.h"

int main (void) {
    black_point_list_t *result = play(20000);
    matrix_t *matrix = black_points_to_matrix(result);
    size_t width = width_of_black_point_list(result);
    matrix_print(width, matrix);

    return 0;
}
