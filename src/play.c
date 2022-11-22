#include <stdlib.h>
#include "../include/play.h"
#include "../include/black_point_list.h"
#include "../include/ant.h"
#include "../include/automaton_context.h"

black_point_list_t *play(uint32_t step) {
    ant_t ant = ant_new();
    black_point_list_t *list = black_point_list_new();

    for (size_t i = 0; i < step; ++i) {
        if (black_point_list_contains(list, ant.point)) {
            ant = play_ant_on_black(&ant, list);
        } else {
            ant = play_ant_on_white(&ant, list);
        }
    }
    black_point_list_normalize_point(list);

    return list;
}

ant_t play_ant_on_black(const ant_t *ant, black_point_list_t *list) {

        const ant_t ant_rotated = ant_rotate_left(ant);
        black_point_list_remove(list, ant_rotated.point);
        const ant_t ant_moved = ant_move_forward(&ant_rotated);

        return ant_moved;
}

ant_t play_ant_on_white(const ant_t *ant, black_point_list_t *list) {

        const ant_t ant_rotated = ant_rotate_right(ant);
        black_point_list_add(list, ant_rotated.point);
        const ant_t ant_moved = ant_move_forward(&ant_rotated);

        return ant_moved;
}


black_point_list_t *play_automaton(uint32_t step) {

    automaton_context_t *context = automaton_context_new();

    for (size_t i = 0; i < step; ++i) {
        automaton_context_t *context_new = automaton_context_update(context);
        automaton_context_free(context);

        context = context_new;
    }

    black_point_list_normalize_point(context->black_point_list);

    return context->black_point_list;
}
