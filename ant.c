#include "ant.h"
#include "common.h"

ant_t ant_new(void) {
    ant_t ant = {
        .direction = TO_LEFT,
        .point = point_new_noheap(0, 0)
    };

    return ant;
}

ant_t ant_with_point(const ant_t *ant, int32_t x, int32_t y) {
    ant_t ant_ = {
        .direction = ant->direction,
        .point = point_new_noheap(x, y)
    };

    return ant_;
}

ant_t ant_move_forward(const ant_t* ant) {

    if (ant->direction == TO_UP) {
        return ant_with_point(ant, ant->point.x, ant->point.y - 1);
    }
    if (ant->direction == TO_DOWN) {
        return ant_with_point(ant, ant->point.x, ant->point.y + 1);
    }
    if (ant->direction == TO_RIGHT) {
        return ant_with_point(ant, ant->point.x + 1, ant->point.y);
    }
    if (ant->direction == TO_LEFT) {
        return ant_with_point(ant, ant->point.x - 1, ant->point.y);
    }

    return *ant;
}

ant_t ant_rotate_right(const ant_t* ant) {
    ant_t ant_ = {
        .point = ant->point,
        .direction = (ant->direction + 1) % 4
    };

    return ant_;
}

ant_t ant_rotate_left(const ant_t* ant) {
    ant_t ant_ = {
        .point = ant->point,
        .direction = (4 + ant->direction - 1) % 4
    };

    return ant_;
}
