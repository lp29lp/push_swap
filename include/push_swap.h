/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:20:10 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/05 01:37:40 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "./libft/libft.h"

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
}	t_ps;

t_node	*new_node(int numb);
int		check_list(t_node **node_bckp, int t_num, t_ps *ps);
int		main(int ac, char **ag);
int		ft_isdigitChar(char *c);
void	move_sa(t_ps *ps);
void	move_sb(t_ps *ps);
void    aux_ss(t_node **node);
void	move_ss(t_ps *ps);



#endif