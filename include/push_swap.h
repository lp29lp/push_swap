/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:20:10 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/07 01:22:17 by lpaulo-d         ###   ########.fr       */
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

#endif