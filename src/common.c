#include <stdlib.h>
#include "../include/common.h"

direction_t direction_rotate_right(direction_t direction) {
    return (direction + 1) % 4;
}

direction_t direction_rotate_left(direction_t direction) {
    return (direction + 3) % 4;
}

point_t point_new_noheap(int32_t x, int32_t y) {
    const point_t point = {
        .x = x,
        .y = y,
        .used = true
    };

    return point;
}

point_t* point_new(int32_t x, int32_t y) {
    point_t* point_ = malloc(sizeof(*point_));
    {
        point_->x = x;
        point_->y = y;
        point_->used = true;
    }

    return point_;
}

point_t point_move_forward(point_t point, direction_t direction) {
    if (direction == TO_UP) {
        return point_new_noheap(point.x, point.y - 1);
    }
    if (direction == TO_RIGHT) {
        return point_new_noheap(point.x + 1, point.y);
    }
    if (direction == TO_DOWN) {
        return point_new_noheap(point.x, point.y + 1);
    }
    if (direction == TO_LEFT) {
        return point_new_noheap(point.x - 1, point.y);
    }

    return point;
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
