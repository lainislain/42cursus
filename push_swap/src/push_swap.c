#include "push_swap.h"

void    init_state(t_state *state, int argc, char **argv)
{
    int     i;
    int     n;
    t_pile  *tmp;

    i = 0;
    argc--;
    argv++;
    state->size = argc;
    state->pile_b = NULL;
    state->pile_a = NULL;
    state->error = 0;
    state->nb_iters = 0;
    state->array = (int*)malloc(sizeof(int) * argc);
    while(i < argc)
    {
        if(!ft_isnum(*argv))
        {
            state->error = 0;
            //exit_state(state);
            break;
        }
        n = ft_atoi(*argv);
        state->array[i] = n;
        tmp = (t_pile*)malloc(sizeof(t_pile));
        tmp->value = n;
        tmp->partition = 0;
        tmp->next = NULL;
        add_back_pile(&state->pile_a, tmp);
        argv++;
        i++;
    }
}

void    print_state(t_state *state)
{
    t_pile      *tmp;
    int         i;

    tmp = state->pile_a;
    printf("===> Pile A:\n");
    while(tmp)
    {
        printf("%d\n",tmp->value);
        tmp = tmp->next;
    }
    tmp = state->pile_b;
    printf("===> Pile B:\n");
    while(tmp)
    {
        printf("%d\n",tmp->value);
        tmp = tmp->next;
    }
    printf("===> Array:\n");
    i = 0;
    while (i < state->size)
    {
        printf("%d\n",state->array[i]);
        i++;
    }
    printf("===> Midpoint is: %d\n", state->array[state->size / 2 ]);
}

void    exit_state(t_state *state)
{
    return ;
}

void    check_state(t_state *state)
{
    return ;
}

int     main(int argc, char **argv)
{
    t_state     state;
    t_pile      *tmp;
    int         i;

    i = 0;
    init_state(&state, argc, argv);
    check_state(&state);
    while(i < 5)
    {
        tmp = (t_pile*)malloc(sizeof(t_pile));
        tmp->value = i;
        tmp->next = NULL;
        add_back_pile(&(&state)->pile_b, tmp);
        i++;
    }
    rrr(&state);
    bubble_sort(state.array, state.size);
    print_state(&state);
    return (0);
}