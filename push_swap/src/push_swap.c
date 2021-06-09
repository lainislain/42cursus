#include "push_swap.h"

void    rrr(t_state *state)
{
    rra(state);
    rrb(state);
}

void    add_back_pile(t_pile **pile, t_pile *stack)
{
    t_pile  *tmp;

    if(!pile)
    {
        pile = (t_pile**)stack;
        return ;
    }
    tmp = (t_pile*)pile;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = stack;
}

void    init_state(t_state *state, int argc, char **argv)
{
    int     i;
    t_pile  *tmp;

    i = 0;
    argc--;
    argv++;
    state->size = argc;
    state->pile_b = NULL;
    state->pile_a = NULL;
    state->nb_iters = 0;
    while(i < argc)
    {
        tmp = (t_pile*)malloc(sizeof(t_pile));
        tmp->value = ft_atoi(*argv);
        tmp->next = NULL;
        add_back_pile(&state->pile_a, tmp);
        argv++;
        i++;
    }
}

int main(int argc, char **argv)
{
    t_state     state;
    t_pile      *tmp;
    int         i;

    i = 0;
    init_state(&state, argc, argv);
    while(i < 5)
    {
        tmp = (t_pile*)malloc(sizeof(t_pile));
        tmp->value = i;
        tmp->next = NULL;
        add_back_pile(&(&state)->pile_b, tmp);
        i++;
    }
    rrr(&state);
    tmp = state.pile_a;
    printf("===> Pile A:\n");
    while(tmp)
    {
        printf("%d\n",tmp->value);
        tmp = tmp->next;
    }
    tmp = state.pile_b;
    printf("===> Pile B:\n");
    while(tmp)
    {
        printf("%d\n",tmp->value);
        tmp = tmp->next;
    }
    return (0);
}