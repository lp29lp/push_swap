/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:32:04 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/08 17:56:27 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	index_small(t_ps *ps)
{
	if (ps->size_stack_a == 2)
		move_sa(ps);
	if (ps->size_stack_a == 3)
		three_numbers(ps);
	if (ps->size_stack_a == 4)
		four_numbers(ps);
	if (ps->size_stack_a == 5)
		five_numbers(ps);
}

int	get_min(t_ps *ps)
{
	t_node	*temp;
	int		min;

	temp = ps->stack_a;
	min = temp->data;
	while (temp != NULL)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

int	get_nextmin(t_ps *ps)
{
	t_node	*temp;
	int		nm;
	int		bnm;

	temp = ps->stack_a;
	nm = temp->data;
	while (temp->next != NULL)
	{
		if (nm > temp->next->data)
		{
			bnm = nm;
			nm = temp->next->data;
			if (nm == ps->min)
				nm = bnm;
		}
		temp = temp->next;
	}
	return (nm);
}

int	get_max(t_ps *ps, int i)
{
	t_node	*temp;
	int		max;
	if (i == 0)
		temp = ps->stack_a;
	else
		temp = ps->stack_b;
	max = temp->data;
	while (temp != NULL)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	return (max);
}

void	get_three(t_ps *ps)
{
	ps->top = ps->stack_a->data;
	ps->mid = ps->stack_a->next->data;
	ps->bottom = ps->stack_a->next->next->data;
}