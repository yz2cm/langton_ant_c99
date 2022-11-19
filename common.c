#include <stdlib.h>
#include "common.h"

point_t point_new_noheap(int32_t x, int32_t y) {
    point_t point = {
        .x = x,
        .y = y,
        .used = true
    };

    return point;
}

point_t* point_new(int32_t x, int32_t y) {
    point_t* point_ = malloc(sizeof(*point_));
    point_->x = x;
    point_->y = y;
    point_->used = true;

    return point_;
}

char color_to_symbol(cell_color_t color) {
    if (color == WHITE) {
        return '_';
    } else {
        return 'X';
    }
}

void colors_to_symbols(char *symbols, const cell_color_t *colors, size_t length) {
    for(size_t i = 0; i < length; ++i) {
        symbols[i] = color_to_symbol(colors[i]);
    }
}
