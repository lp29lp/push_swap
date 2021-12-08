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

#include <push_swap.h>

static int	create_stack(t_node **head, char **av, t_ps *ps);
static void	init_list(t_ps *ps);
static void	count_av(char **av, t_ps *ps);

int	main(int ac, char **av)
{
	t_ps	ps;
	t_node	*aux;

	if (ac <= 2)
	{
		exit(1);
	}
	init_list(&ps);
	create_stack(&ps.stack_a, av, &ps);
	check_if_complete(&ps);
	if (ac <= 6)
		index_small(&ps);
	else
		big_stack(&ps);
	aux = ps.stack_a;
	while (aux != NULL)
	{
		printf("stack_a: %d\n", aux->data);
		aux = aux->next;
	}
	printf("Stack_a size: %d\n", ps.size_stack_a);
	printf("Stack_b size: %d\n", ps.size_stack_b);
	printf("movementos: %d\n", ps.movements);
	printf("\n");
	aux = ps.stack_b;
	while (aux != NULL)
	{
		printf("stack_b: %d\n", aux->data);
		aux = aux->next;
	}
	if (check_if_complete(&ps) == 0)
		printf("nao ta\n");
	free_stack(&ps);
	exit(0);
}

static int	create_stack(t_node **head, char **av, t_ps *ps)
{
	t_node	*temp;
	int		i;
	int		t_num;

	temp = *head;
	i = 1;
	count_av(av, ps);
	while (av[i] != NULL && ft_isdigitChar(av[i], ps) == 1)
	{
		t_num = ft_atoi(av[i]);
		check_list(head, t_num, ps);
		temp->data = t_num;
		if ((ps->limit - 1) == i)
		{
			ps->size_stack_a++;
			return (1);
		}
		temp->next = new_node(t_num);
		temp = temp->next;
		i++;
		ps->size_stack_a++;
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
	ps->c_chunk = 0;
	ps->i = 0;
}

static void	count_av(char **av, t_ps *ps)
{
	ps->limit = 1;
	while (av[ps->limit] != NULL)
		ps->limit++;
}
