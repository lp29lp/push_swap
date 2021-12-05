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
static void	free_stack(t_ps *ps);
int	checkAv(char *av);

int	main(int ac, char **av)
{
	int x = 0;
	t_ps	ps;
	t_node	*aux;
	if (ac <= 2)
		exit(1);
	init_list(&ps);
	create_stack(&ps.stack_a, av, &ps);
	//while (ps.stack_a->next)
	//{
	//	printf("stack(a) = %d\n",ps.stack_a->data);
	//	ps.stack_a = ps.stack_a->next;
	//	x++;
	//}
	//printf("stack(a) = %d\n",ps.stack_a->data);
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
		if (ft_isdigitChar(av[i]))
		{
			t_num = ft_atoi(av[i]);//primeiro ver se e digito arrumar se caso houver letra
			check_list(node_bckp, t_num, ps);
			if (ft_isdigit(t_num))
			{
				temp->data = t_num;
				temp->next = new_node(t_num);
				temp = temp->next;
			}
			else
				exit(1);
			i++;
			ps->size_stack_a++;
		}
		else
		{
			printf("matou\n");
			exit(1);
		}
	}
	//ps->last = temp;
	return (1);
}
static void	init_list(t_ps *ps)
{
	ps->stack_a = new_node(0);
	ps->stack_b = new_node(0);
	ps->size_stack_a = 0;
	ps->size_stack_b = 0;
	ps->movements = 0;
}

static void	free_stack(t_ps *ps)
{
	t_node	*temp;
	temp = ps->stack_a;
	while(temp->next != NULL)
	{
		temp = temp->next;
		free(ps->stack_a);
		ps->stack_a = temp;
	}
	free(ps->stack_a);
	return ;
}
