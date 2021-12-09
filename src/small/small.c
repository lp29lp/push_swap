/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 06:05:55 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/09 01:08:11 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	three_numbers(t_ps *ps)
{
	get_three(ps);
	if (ps->bottom > ps->top && ps->bottom < ps->mid)
	{
		move_rra(ps, 0);
		move_sa(ps);
	}
	if (ps->bottom > ps->mid && ps->bottom > ps->top && ps->top > ps->mid)
		move_sa(ps);
	if (ps->bottom < ps->top && ps->bottom < ps->mid)
	{
		if (ps->top > ps->mid && ps->mid > ps->bottom)
			move_sa(ps);
		move_rra(ps, 0);
	}
	if (ps->bottom > ps->mid && ps->bottom < ps->top)
		move_ra(ps);
}

void	four_numbers(t_ps *ps)
{
	int		min;
	int		max;

	min = get_min(ps);
	max = get_max(ps, 0);
	if (ps->stack_a->data == min || ps->stack_a->data == max)
		move_pb(ps);
	else if (ps->stack_a->next->data == min || ps->stack_a->next->data == max)
	{
		move_sa(ps);
		move_pb(ps);
	}
	else
	{
		move_rra(ps, 0);
		move_pb(ps);
	}
	three_numbers(ps);
	if (ps->stack_b->data == max)
	{
		move_pa(ps);
		move_ra(ps);
	}
	else
		move_pa(ps);
}

void	five_numbers(t_ps *ps)
{
	t_node	*temp;

	ps->min = get_min(ps);
	ps->max = get_max(ps, 0);
	ps->next_min = get_nextmin(ps);
	five_cont_one(ps);
	three_numbers(ps);
	temp = ps->stack_b;
	five_cont_two(ps, temp);
}

void	five_cont_two(t_ps *ps, t_node *temp)
{
	temp = ps->stack_b;
	ps->first = temp->data;
	ps->last = temp->next->data;
	if (ps->first < ps->last)
	{
		move_sb(ps);
		move_pa(ps);
		move_ra(ps);
		move_pa(ps);
	}
	else if (ps->first > ps->last)
	{
		move_pa(ps);
		move_ra(ps);
		move_pa(ps);
	}
	else
	{
		move_pa(ps);
		move_pa(ps);
	}
}

void	five_cont_one(t_ps *ps)
{
	t_node	*temp;

	temp = ps->stack_a;
	while (ps->size_stack_b <= 2)
	{
		if (temp->data == ps->min || temp->data == ps->max)
		{
			move_pb(ps);
			temp = ps->stack_a;
			continue ;
		}
		if (temp->next->data == ps->min || temp->next->data == ps->max)
		{
			move_sa(ps);
			move_pb(ps);
			temp = ps->stack_a;
			continue ;
		}
		else
		{
			move_rra(ps, 0);
			temp = ps->stack_a;
			continue ;
		}
	}
}
