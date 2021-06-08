#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct		s_pile
{
	struct s_pile	*next;
	int				value;
}					t_pile;

typedef struct		s_state
{
	t_pile			*pile_a;
	t_pile			*pile_b;
	int				size;
    int             nb_iters;
}					t_state;

#endif