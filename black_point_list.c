#include <stdlib.h>
#include "black_point_list.h"
#include "matrix.h"

black_point_list_t *black_point_list_new() {
    black_point_list_t* list = malloc(sizeof(*list));
    list->points = NULL;
    list->length = 0;
    list->capacity = 0;

    return list;
}
point_t *black_point_list_find_unused(const black_point_list_t *list, point_t point) {
    if (list == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < list->length; ++i) {
        if (list->points[i].x == point.x && list->points[i].y == point.y && list->points[i].used == false) {
            return &(list->points[i]);
        }
    }

    return NULL;
}

point_t *black_point_list_find(const black_point_list_t *list, point_t point) {
    if (list == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < list->length; ++i) {
        if (list->points[i].x == point.x && list->points[i].y == point.y && list->points[i].used == true) {
            return &(list->points[i]);
        }
    }

    return NULL;
}

void black_point_list_add(black_point_list_t *list, point_t point) {
    if (list == NULL) {
        return;
    }

    if (list->points == NULL) {
        list->points = point_new(point.x, point.y);
        list->length ++;
        return;
    }

    point_t *point_unused = black_point_list_find_unused(list, point);
    if (point_unused != NULL) {
        point_unused->used = true;
        return;
    }

    size_t capacity_needs = (list->length + 1) * sizeof(*(list->points));
    if (list->capacity < capacity_needs) {
        list->points = realloc(list->points, capacity_needs * 2);
        list->capacity = capacity_needs * 2;
    }
    *(list->points + list->length) = point;
    list->length++;
}

void black_point_list_remove(const black_point_list_t *list, point_t point) {
    if(list == NULL) {
        return;
    }
    point_t *point_ = black_point_list_find(list, point);
    if(point_ == NULL) {
        return;
    }

    point_->used = false;
}

int32_t max_x_of_black_points(const black_point_list_t *list) {
    int max_x = list->points[0].x;
    for (size_t i = 0; i < list->length; ++i) {
        max_x = list->points[i].used && max_x < list->points[i].x ? list->points[i].x : max_x;
    }

    return max_x;
}

int32_t min_x_of_black_points(const black_point_list_t *list) {
    int min_x = list->points[0].x;
    for (size_t i = 0; i < list->length; ++i) {
        min_x = list->points[i].used && list->points[i].x < min_x ? list->points[i].x : min_x;
    }

    return min_x;
}

int32_t max_y_of_black_points(const black_point_list_t *list) {
    int max_y = list->points[0].y;
    for (size_t i = 0; i < list->length; ++i) {
        max_y = list->points[i].used && max_y < list->points[i].y ? list->points[i].y : max_y;
    }

    return max_y;
}

int32_t min_y_of_black_points(const black_point_list_t *list) {
    int min_y = list->points[0].y;
    for (size_t i = 0; i < list->length; ++i) {
        min_y = list->points[i].used && list->points[i].y < min_y ? list->points[i].y : min_y;
    }

    return min_y;
}

size_t width_of_black_point_list(black_point_list_t *list) {
    int32_t min_x = min_x_of_black_points(list);
    int32_t max_x = max_x_of_black_points(list);
    size_t width = max_x - min_x + 1;

    return width;
}

matrix_t* black_points_to_matrix(const black_point_list_t *list) {
    point_t min, max;
    min.x = min_x_of_black_points(list);
    min.y = min_y_of_black_points(list);
    max.x = max_x_of_black_points(list);
    max.y = max_y_of_black_points(list);
    matrix_t *matrix = matrix_new();
    point_t point = point_new_noheap(0, 0);

    for(int32_t y = min.y; y <= max.y; ++y) {
        for(int32_t x = min.x; x <= max.x; ++x) {
            point.x = x;
            point.y = y;
            if (black_point_list_find(list, point) == NULL) {
                matrix_add_cell(matrix, WHITE);
            } else {
                matrix_add_cell(matrix, BLACK);
            }
        }
    }

    return matrix;
}
