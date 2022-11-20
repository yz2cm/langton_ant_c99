#include <stdlib.h>
#include "black_point_list.h"
#include "common.h"

black_point_list_t *black_point_list_new(void) {
    black_point_list_t* list = malloc(sizeof(*list));
    list->points = NULL;
    list->length = 0;
    list->capacity = 0;

    return list;
}

void black_point_list_resize(black_point_list_t *list, size_t new_capacity) {
        if (list == NULL) {
            return;
        }

        if (new_capacity <= list->capacity) {
            return;
        }

        list->points = realloc(list->points, new_capacity);
        list->capacity = new_capacity;
}

size_t black_point_list_calc_capacity_needed(const black_point_list_t *list, size_t points_length) {
    const size_t capacity_needed = points_length * sizeof(*(list->points));
    if(list->capacity < capacity_needed) {
        return capacity_needed * 2;
    } else {
        return list->capacity;
    }
}

point_t *black_point_list_find(const black_point_list_t *list, point_t point) {
    if (list == NULL) {
        return NULL;
    }

    if (list->points == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < list->length; ++i) {
        if (list->points[i].x == point.x && list->points[i].y == point.y) {
            return list->points + i;
        }
    }

    return NULL;
}

bool black_point_list_contains(const black_point_list_t *list, point_t point) {
    const point_t *point_ = black_point_list_find(list, point);
    return point_ != NULL && point_->used;
}

void black_point_list_add(black_point_list_t *list, point_t point) {
    if (list == NULL) {
        return;
    }

    point_t *point_ = black_point_list_find(list, point);
    if (point_ != NULL) {
        // reuse disabled entry if exists.
        point_->used = true;
    } else {
        // register new entry if not exist.
        const size_t capacity_needs = black_point_list_calc_capacity_needed(list, list->length + 1);
        black_point_list_resize(list, capacity_needs);
        *(list->points + list->length) = point;
        list->length++;
    }
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

int32_t black_point_list_max_x(const black_point_list_t *list) {
    int max_x = list->points[0].x;
    for (size_t i = 0; i < list->length; ++i) {
        max_x = list->points[i].used && max_x < list->points[i].x ? list->points[i].x : max_x;
    }

    return max_x;
}

int32_t black_point_list_min_x(const black_point_list_t *list) {
    int min_x = list->points[0].x;
    for (size_t i = 0; i < list->length; ++i) {
        min_x = list->points[i].used && list->points[i].x < min_x ? list->points[i].x : min_x;
    }

    return min_x;
}

int32_t black_point_list_max_y(const black_point_list_t *list) {
    int max_y = list->points[0].y;
    for (size_t i = 0; i < list->length; ++i) {
        max_y = list->points[i].used && max_y < list->points[i].y ? list->points[i].y : max_y;
    }

    return max_y;
}

int32_t black_point_list_min_y(const black_point_list_t *list) {
    int min_y = list->points[0].y;
    for (size_t i = 0; i < list->length; ++i) {
        min_y = list->points[i].used && list->points[i].y < min_y ? list->points[i].y : min_y;
    }

    return min_y;
}
