#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct		s_pile
{
	struct s_pile	*next;
	struct s_pile	*prev;
	int				partition;
	int				value;
}					t_pile;

typedef struct		s_state
{
	t_pile			*pile_a;
	t_pile			*pile_b;
	int				error;
	int				size;
    int             nb_iters;
	int				*array;
}					t_state;

void    sa(t_state *state);
void    sb(t_state *state);
void    ss(t_state *state);
void    pb(t_state *state);
void    pa(t_state *state);
void    ra(t_state *state);
void    rb(t_state *state);
void    rr(t_state *state);
void    rra(t_state *state);
void    rrb(t_state *state);
void    rrr(t_state *state);
int     ft_isnum(char *str);
int     ft_issign(char c);
void    add_back_pile(t_pile **pile, t_pile *stack);
void    init_state(t_state *state, int argc, char **argv);
void    exit_state(t_state *state);
void    print_state(t_state *state);
void    next_state(t_state *state);
void	bubble_sort(int arr[], int n);
int     pile_is_sorted(t_pile* pile);
int     check_duplicate(t_state *state, int n);

#endif