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
    cell_color_t *color;
    size_t length;
    size_t capacity;
} matrix_t;

point_t point_new_noheap(int32_t x, int32_t y);
point_t* point_new(int32_t x, int32_t y);
char color_to_symbol(cell_color_t color);

#endif