/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 04:01:22 by amaghat           #+#    #+#             */
/*   Updated: 2021/06/09 04:01:22 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				size;
    char			**instructs;
	int				n_parts;
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
char	*ft_read_instructs(t_state *checker);
char	*ft_read_instruct(void);
void	ft_check_instruct(t_state *state, char *str);
void	ft_exec_instructs(t_state *checker);
void	ft_checker(t_state *checker);
int		ft_find_midpoint(t_pile *pile);
void	ft_rev_pushrot(t_state *state);
void	ft_pushrot(t_state *state, int rot);
int		ft_midpointalgo(t_state *state, int midpoint, int part);
void	ft_revmidpointalgo(t_state *state);
int		ft_len_pile(t_pile *pile);
int		ft_lastinpile_a(t_state *state);
int		ft_len_partition(t_state *state, int part);
int		ft_check_inf(t_pile *pile, int midpoint);
int		ft_check_sup(t_pile *pile, int midpoint);
void	mini_sort(t_state *state);


#endif