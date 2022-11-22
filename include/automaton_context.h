#ifndef __YZ2CM_LANGTON_ANT_AUTOMATON_CONTEXT_H__
#define __YZ2CM_LANGTON_ANT_AUTOMATON_CONTEXT_H__

automaton_context_t *automaton_context_new(void);
void                 automaton_context_free(automaton_context_t *context);
automaton_context_t *automaton_context_clone(const automaton_context_t *context);
automaton_context_t *automaton_context_update(const automaton_context_t *context);

#endif
