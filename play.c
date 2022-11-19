#include "play.h"
#include "black_point_list.h"
#include "ant.h"

ant_t play_once(const ant_t *ant, black_point_list_t *list) {
    
    if (black_point_list_contains(list, ant->point)) {
        const ant_t ant_rotated = ant_rotate_left(ant);
        black_point_list_remove(list, ant_rotated.point);
        const ant_t ant_moved = ant_move_forward(&ant_rotated);

        return ant_moved;
    } else {
        const ant_t ant_rotated = ant_rotate_right(ant);
        black_point_list_add(list, ant_rotated.point);
        const ant_t ant_moved = ant_move_forward(&ant_rotated);

        return ant_moved;
    }
}

black_point_list_t *play(uint32_t step) {
    ant_t ant = ant_new();
    black_point_list_t *list = black_point_list_new();

    for (size_t i = 0; i < step; ++i) {
        ant = play_once(&ant, list);
    }

    return list;
}
