/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:19:43 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/06 17:19:43 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//calloc to init memory
t_node	*new_node(int numb)
{
	t_node	*new;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (new == NULL)
		exit(1);
	new->next = NULL;
	new->data = numb;
	return (new);
}

int	check_list(t_node **node_bckp, int t_num, t_ps *ps)
{
	t_node	*temp;

	temp = *node_bckp;
	if (temp->next == NULL)
		return (1);
	while (temp->next != NULL)
	{
		if (temp->data == t_num)
		{
			ft_putendl_fd("Error", 1);
			free_stack(ps);
			exit(1);
		}
		temp = temp->next;
	}
	return (1);
}

int	ft_isdigit_char(char *c, t_ps *ps)
{
	int	i;

	i = 0;
	if (c[i] == '-' || c[i] == '+')
		i++;
	while (c[i] != '\0')
	{
		if (c[i] >= '0' && c[i] <= '9')
			i++;
		else
		{
			ft_putendl_fd("Error", 1);
			free_stack(ps);
			exit(0);
		}
	}
	return (1);
}

void	free_stack(t_ps *ps)
{
	t_node	*temp;

	temp = ps->stack_a;
	if (temp != NULL)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
			free(ps->stack_a);
			ps->stack_a = temp;
		}
	}
	free(ps->stack_a);
	if (ps->size_stack_b > 1)
	{
		temp = ps->stack_b;
		while (temp->next)
		{
			temp = temp->next;
			free(ps->stack_b);
			ps->stack_b = temp;
		}
	}
	free(ps->stack_b);
	return ;
}
