#include <stdlib.h>
#include "../include/common.h"
#include "../include/automaton_context.h"
#include "../include/black_point_list.h"

automaton_context_t *automaton_context_new(void) {

    automaton_context_t *context = malloc(sizeof(*context));
    {
        context->direction = TO_LEFT;
        context->point = point_new_noheap(0, 0);
        context->black_point_list = black_point_list_new();
    }

    return context;
}

void automaton_context_free(automaton_context_t *context) {
    if(context == NULL) {
        return;
    }

    black_point_list_free(context->black_point_list);
    context->black_point_list = NULL;

    free(context);
}

automaton_context_t *automaton_context_clone(const automaton_context_t *context) {
    automaton_context_t *context_new = automaton_context_new();
    {
        context_new->direction = context->direction;
        context_new->point = context->point;
        context_new->black_point_list = black_point_list_clone(context->black_point_list);
    }

    return context_new;
}

automaton_context_t *automaton_context_update(const automaton_context_t *context) {

    automaton_context_t *context_new = automaton_context_clone(context);

    if (black_point_list_contains(context->black_point_list, context->point)) {
        context_new->direction = direction_rotate_left(context->direction);
        black_point_list_remove(context_new->black_point_list, context->point);
    } else {
        context_new->direction = direction_rotate_right(context->direction);
        black_point_list_add(context_new->black_point_list, context->point);
    }

    context_new->point = point_move_forward(context->point, context_new->direction);

    return context_new;
}
