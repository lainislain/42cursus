#include "push_swap.h"

void    rrr(t_state *state)
{
    rra(state);
    rrb(state);
}

int     ft_issign(char c)
{
    if (c == '+' || c == '-' || ft_isdigit(c))
        return (1);
    else
        return (0);
}

int     ft_isnum(char *str)
{
    int     i;
    int     n;

    if (!str || !str[0] || !ft_issign(str[0]))
        return (0);
    i = 1;
    n = ft_strlen(str);
    while (i < n)
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
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
    state->error = 0;
    state->nb_iters = 0;
    while(i < argc)
    {
        if(!ft_isnum(*argv))
        {
            state->error = 0;
            //exit_state(state);
            break;
        }
        tmp = (t_pile*)malloc(sizeof(t_pile));
        tmp->value = ft_atoi(*argv);
        tmp->next = NULL;
        add_back_pile(&state->pile_a, tmp);
        argv++;
        i++;
    }
}

void    print_state(t_state *state)
{
    t_pile      *tmp;

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
}

void    exit_state(t_state *state)
{
    return ;
}

void    check_state(t_state *state)
{
    return ;
}

int main(int argc, char **argv)
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
    print_state(&state);
    return (0);
}