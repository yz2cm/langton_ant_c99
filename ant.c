#include "ant.h"
#include "common.h"

ant_t ant_new() {
    ant_t ant = {
        .direction = TO_LEFT,
        .point = point_new_noheap(0, 0)
    };

    return ant;
}

ant_t move_forward_ant(const ant_t* ant) {
    ant_t ant_ = {
        .direction = ant->direction,
        .point = ant->point
    };

    if (ant->direction == TO_UP) {
        ant_.point.y += -1;
    } else if (ant->direction == TO_DOWN) {
        ant_.point.y += 1;
    } else if (ant->direction == TO_RIGHT) {
        ant_.point.x += 1;
    } else if (ant->direction == TO_LEFT) {
        ant_.point.x += -1;
    }

    return ant_;
}

ant_t rotate_right_ant(const ant_t* ant) {
    ant_t ant_ = {
        .point = ant->point,
        .direction = (ant->direction + 1) % 4
    };

    return ant_;
}

ant_t rotate_left_ant(const ant_t* ant) {
    ant_t ant_ = {
        .point = ant->point,
        .direction = (4 + ant->direction - 1) % 4
    };

    return ant_;
}
