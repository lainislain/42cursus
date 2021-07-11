/* ************************************************************************** */
/*	                                                                          */
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

# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_pile
{
	struct s_pile	*next;
	struct s_pile	*prev;
	int				partition;
	int				value;
}				t_pile;

typedef struct s_state
{
	t_pile			*pile_a;
	t_pile			*pile_b;
	int				size;
	char			**instructs;
}				t_state;

void		sa(t_state *state, int check);
void		sb(t_state *state, int check);
void		ss(t_state *state, int check);
void		pb(t_state *state, int check);
void		pa(t_state *state, int check);
void		ra(t_state *state, int check);
void		rb(t_state *state, int check);
void		rr(t_state *state, int check);
void		rra(t_state *state, int check);
void		rrb(t_state *state, int check);
void		rrr(t_state *state, int check);
long long	ft_atol(const char *str);
int			ft_isnum(char *str);
int			ft_issign(char c);
void		add_back_pile(t_pile **pile, t_pile *stack);
void		init_state(t_state *state, int argc, char **argv);
void		exit_state(t_state *state);
void		print_state(t_state *state);
void		bubble_sort(int arr[], int n);
int			pile_is_sorted(t_pile *pile);
int			part_is_sorted(t_pile *pile);
int			check_duplicate(t_state *state, int n);
char		*ft_read_instructs(t_state *checker);
char		*ft_read_instruct(void);
void		ft_check_instruct(t_state *state, char *str);
void		ft_exec_instructs(t_state *checker);
void		ft_checker(t_state *checker);
int			ft_find_midpoint(t_pile *pile);
void		ft_rev_pushrot(t_state *state);
void		ft_pushrot(t_state *state, int rot);
int			iter_atob(t_state *state, int midpoint, int part);
void		iter_btoa(t_state *state);
int			ft_len_pile(t_pile *pile);
int			ft_len_partition(t_pile *pile);
int			ft_check_inf(t_pile *pile, int midpoint);
int			ft_check_sup(t_pile *pile, int midpoint);
void		mini_sort(t_state *state);
void		ft_midpoint_algo(t_state *state);
void		ft_rev_pushrot(t_state *state);
void		init_state_condition(t_state *state, long long n, char **argv);
void		finish_shunk(t_state *state, t_pile *tmp);
#endif
