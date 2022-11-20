#include "matrix_line.h"
#include "common.h"

matrix_line_t matrix_line_new_noheap(const cell_color_t *colors, size_t length) {
    matrix_line_t a_line = {
        colors = colors,
        length = length
    };

    return a_line;
}
