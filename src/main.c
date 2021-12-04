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
int	free_function(t_ps *ps, t_node *head);

int	main(int ac, char **av)
{
	t_ps	ps;//nao e a linked list as stacks ta la dentro mas n e t_node
	t_node *aux;
	if (ac <= 1)
		return (EXIT_SUCCESS);
	init_list(&ps);
	create_stack(&ps.stack_a, av, &ps);
	aux = ps.stack_a;
	while (aux->next != NULL)
	{
		printf("%d\n", aux->data);
		aux = aux->next;
	}
	return (0);
	free_function(&ps, ps.stack_a);
}

static int	create_stack(t_node **node_bckp, char **av, t_ps *ps)
{
	printf("entrou\n");
	t_node	*temp;
	t_node	*head;
	int		i;
	int		t_num;

	head = *node_bckp;
	temp = *node_bckp;
	i = 1;
	while (av[i] != NULL)
	{
		t_num = ft_atoi(av[i]);
		//if (t_num == NULL)
		//	return (0);
		if (ft_isdigit(t_num) && !(temp == *node_bckp))
		{
			temp->next = new_node(t_num);
			temp = temp->next;
		}
		else if (ft_isdigit(t_num) && temp == *node_bckp)
		{
			temp->data = t_num;
			temp->next = NULL;
		}
		else
			return (0);
		i++;
		check_list(*node_bckp, t_num, ps);
	}
	//free(temp)//relmente necessario?
	return (1);
}

static void	init_list(t_ps *ps)
{
	ps->stack_a = new_node(0);
	ps->stack_b = new_node(0);
}

int	free_function(t_ps *ps, t_node *head)
{
	t_node	*temp;
	temp = ps->stack_a;

	while(temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
	if (head == NULL)
	{
		printf("deleted completed\n");
		return (0);
	}
	return (1);
}