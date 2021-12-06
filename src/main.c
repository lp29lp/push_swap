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

static int	create_stack(t_node **node_bckp, char **av, t_ps *ps);
static void	init_list(t_ps *ps);

int	main(int ac, char **av)
{
	t_ps	ps;

	if (ac <= 2)
	{
		ft_putendl_fd("Need more arguments", 1);
		exit(1);
	}
	init_list(&ps);
	create_stack(&ps.stack_a, av, &ps);
	if (check_if_complete(&ps) == 0)
	{
		ft_putendl_fd("Alredy sorted", 1);
		free_stack(&ps);
		exit(1);
	}
	free_stack(&ps);
	exit(0);
}

static int	create_stack(t_node **node_bckp, char **av, t_ps *ps)
{
	t_node	*temp;
	int		i;
	int		t_num;

	temp = *node_bckp;
	i = 1;
	while (av[i] != NULL)
	{
		if (ft_isdigitChar(av[i], ps))
		{
			t_num = ft_atoi(av[i]);
			check_list(node_bckp, t_num, ps);
			temp->data = t_num;
			temp->next = new_node(t_num);
			temp = temp->next;
			i++;
			ps->size_stack_a++;
		}
	}
	return (1);
}

static void	init_list(t_ps *ps)
{
	ps->stack_a = new_node(0);
	ps->stack_b = new_node(0);
	ps->size_stack_a = 0;
	ps->size_stack_b = 1;
	ps->movements = 0;
}
