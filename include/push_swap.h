/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:20:10 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/04 15:01:43 by lpaulo-d         ###   ########.fr       */
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
	struct s_node	*prev;
	int				numb;
}	t_node;

typedef struct s_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_swap;

t_node	*new_node(int numb);
int		check_list(t_node *node_bckp, int t_num);
int		main(int ac, char **ag);


#endif