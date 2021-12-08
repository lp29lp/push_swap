/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:20:10 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/08 18:11:50 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
typedef struct s_node
{
	struct s_node	*next;
	int				data;
}	t_node;

typedef struct s_ps
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_stack_a;
	int		size_stack_b;
	int		movements;
	int		limit;
	int		bottom;
	int		mid;
	int		top;
	int		min;
	int		max;
	int		next_min;
	int		first;
	int		last;
	int		c_chunk;
	int		last_position;
	int		first_position;
	int		hold_first;
	int		hold_second;
	int		value;
	int		i;
}	t_ps;

t_node	*new_node(int numb);
int		check_list(t_node **node_bckp, int t_num, t_ps *ps);
int		main(int ac, char **ag);
int		ft_isdigitChar(char *c, t_ps *ps);
void	move_sa(t_ps *ps);
void	move_sb(t_ps *ps);
void	aux_ss(t_node **node);
void	move_ss(t_ps *ps);
void	move_ra(t_ps *ps);
void	move_rb(t_ps *ps);
void	rotate(t_node **node);
void	move_rr(t_ps *ps);
void	move_pb(t_ps *ps);
void	move_pa(t_ps *ps);
void	move_rra(t_ps *ps, int info);
void	move_rrb(t_ps *ps, int info);
void	move_rrr(t_ps *ps);
void	free_stack(t_ps *ps);
int		ft_atoi(const char *nptr);
int		check_if_complete(t_ps *ps);
size_t	ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigitChar_no_struct(char *c);
void	three_numbers(t_ps *ps);
void	index_small(t_ps *ps);
int		get_min(t_ps *ps);
int		get_max(t_ps *ps, int i);
void	four_numbers(t_ps *ps);
void	get_three(t_ps *ps);
int		get_nextmin(t_ps *ps);
void	five_cont_one(t_ps *ps);
void	five_cont_two(t_ps *ps, t_node *temp);
void	five_numbers(t_ps *ps);
//q vida
int		f_chunk(t_ps *ps);
void	big_stack(t_ps *ps);
void	check_swap(t_ps *ps, int bigf_chunk);
int	get_number(t_ps *ps, int bigf_chunk);
void	check_second(t_ps *ps);
void	back_to_a(t_ps *ps);
void	check(t_ps *ps, int i);
int	get_position(t_ps *ps, int max);
void	find_min(t_ps *ps, int bigf_chunk);
void	parse_to_send(t_ps *ps);
void	check_send(t_ps *ps, int big);
void check_support(t_ps *ps, int cont, int min);

#endif
