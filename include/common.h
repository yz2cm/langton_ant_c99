#ifndef __YZ2CM_LANGTON_ANT_COMMON_H__
#define __YZ2CM_LANGTON_ANT_COMMON_H__
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum {
    WHITE = 0,
    BLACK
} cell_color_t;

typedef enum {
    TO_UP = 0,
    TO_RIGHT,
    TO_DOWN,
    TO_LEFT
} direction_t;

typedef struct{
    int x;
    int y;
    bool used;
} point_t;

typedef struct {
    direction_t direction;
    point_t point;
} ant_t;

typedef struct black_point_list {
    point_t *points;
    size_t length;
    size_t capacity;
} black_point_list_t;

typedef struct {
    cell_color_t *colors;
    size_t width;
    size_t height;
} matrix_t;

typedef struct {
    const cell_color_t *colors;
    size_t length;
} matrix_line_t;

typedef struct {
    matrix_line_t *lines;
    size_t length;
} matrix_line_list_t;

typedef struct {
    direction_t direction;
    point_t point;
    black_point_list_t *black_point_list;
} automaton_context_t;

direction_t direction_rotate_right(direction_t direction);
direction_t direction_rotate_left(direction_t direction);
point_t     point_new_noheap(int32_t x, int32_t y);
point_t    *point_new(int32_t x, int32_t y);
point_t     point_move_forward(point_t point, direction_t direction);
char        color_to_symbol(cell_color_t color);
void        colors_to_symbols(char *symbols, const cell_color_t *colors, size_t length);

#endif
