/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:51:03 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/03 23:51:03 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	create_stack(t_node **node_bckp, char **av, t_ps *ps);
static void	init_list(t_ps *ps);

int	main(int ac, char **ag)
{
	t_ps	ps;//nao e a linked list as stacks ta la dentro mas n e t_node

	if (ac <= 1)
		return (EXIT_SUCCESS);
	init_list(&ps);
	create_stack(&ps.stack_a, av, &ps)
	check_list(&ps);
}

static void	create_stack(t_node **node_bckp, char **av, t_ps *ps)
{
	t_node	temp;
	t_node	head;
	int		i;
	int		t_num;

	head = *node_bckp;
	temp = *node_bckp;
	i = 1
	while (av[i] != NULL)
	{
		t_num = ft_atoi(av[i])
		if (t_num == NULL)
			return (0);
		if (ft_isdigit(t_num) && !(temp == node_bckp))
		{
			temp->next = new_node(t_num);
			temp = temp->next;
		}
		else if (ft_isdigit(t_num) && temp == node)
		{
			node_bckp->data = t_num;
			node_bckp->next = NULL;
		}
		else
			return (0);
		i++;
		check_list(*node_bckp,t_num);
	}
}

static void	init_list(t_ps *ps)
{
	ps->stack_a = new_node(0);
	ps->stack_b = new_node(0);
}

