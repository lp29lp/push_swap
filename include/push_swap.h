/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:20:10 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/11 02:12:15 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./struct.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

t_node	*new_node(int numb);
int		check_list(t_node **node_bckp, int t_num, t_ps *ps);
int		main(int ac, char **ag);
int		ft_isdigit_char(char *c, t_ps *ps);
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
int		check_if_complete(t_ps *ps);
int		ft_isdigitChar_no_struct(char *c);
void	three_numbers(t_ps *ps);
void	index_small(t_ps *ps);
int		get_min(t_ps *ps);
int		get_max(t_ps *ps, int i);
void	four_numbers(t_ps *ps);
void	get_three(t_ps *ps);
void	five_cont_one(t_ps *ps);
void	five_cont_two(t_ps *ps, t_node *temp);
void	five_numbers(t_ps *ps);
void	move_rrb(t_ps *ps, int info);
void	aux_move_pa(t_ps *ps, t_node *new_stack, t_node *aux);
void	aux_move_pb(t_ps *ps, t_node *new_stack, t_node *aux);
int		f_chunk(t_ps *ps);
void	big_stack(t_ps *ps);
void	check_swap(t_ps *ps, int bigf_chunk);
int		get_number(t_ps *ps, int bigf_chunk);
void	check_second(t_ps *ps);
void	back_to_a(t_ps *ps);
void	check(t_ps *ps, int i);
int		get_position(t_ps *ps, int max);
void	find_min(t_ps *ps, int bigf_chunk);
void	parse_to_send(t_ps *ps);
void	check_send(t_ps *ps, int big);
void	check_support(t_ps *ps, int cont, int min);
int		ft_atoi(const char *nptr, t_ps *ps);

#endif
