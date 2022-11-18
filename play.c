#include "play.h"
#include "black_point_list.h"
#include "ant.h"

ant_t play_once(ant_t ant, black_point_list_t *list) {
        if (black_point_list_find(list, ant.point) == NULL) {
            ant = rotate_right_ant(&ant);
            black_point_list_add(list, ant.point);
        } else {
            ant = rotate_left_ant(&ant);
            black_point_list_remove(list, ant.point);
        }
        ant = move_forward_ant(&ant);

        return ant;
}

black_point_list_t *play(uint32_t step) {
    ant_t ant = ant_new();
    black_point_list_t *list = black_point_list_new();

    for (size_t i = 0; i < step; ++i) {
        ant = play_once(ant, list);
    }

    return list;
}
