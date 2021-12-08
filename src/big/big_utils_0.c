/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_utils_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:48:27 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/08 18:11:44 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	find_min(t_ps *ps, int bigf_chunk)//find the first min in current chunk
{
	t_node	*temp;

	temp = ps->stack_a;
	ps->first_position = 0;
	while (temp)
	{
		if (temp->data < bigf_chunk)
		{
			ps->hold_first = temp->data;
			break ;
		}
		ps->first_position++;
		temp = temp->next;
	}
}

void	parse_to_send(t_ps *ps)
{
	t_node	*temp;

	temp = ps->stack_a;
	if (ps->first_position == 0)
	{
		check_send(ps, ps->hold_first);
		move_pb(ps);
		return ;
	}
	while (temp)
	{
		temp = ps->stack_a;
		if (temp->data == ps->hold_first)
		{
			check_send(ps, ps->hold_first);
			move_pb(ps);
			return ;
		}
		move_ra(ps);
	}
}

void	check_send(t_ps *ps, int big)
{
	t_node	*temp;
	
	ps->value = 0;
	if (ps->size_stack_b == 1)
		return ;
	temp = ps->stack_b;
	ps->min = INT_MIN;
	while (temp)
	{
		if (temp->data < big && temp->data > ps->min)
			ps->min = temp->data;
		temp = temp->next;
	}
	temp = ps->stack_b;
	while (temp)
	{
		ps->value++;
		if (temp->data == ps->min)
			check_support(ps, ps->value, ps->min);
		temp = temp->next;
	}
	return ;
}

void check_support(t_ps *ps, int cont, int min)
{
	t_node	*temp;

	temp = ps->stack_b;
	if (cont > (ps->size_stack_b / 2))
	{
		while (temp->data != min)
		{
			move_rrb(ps, 0);
			temp = ps->stack_b;
		}
		return ;
	}
	else
	{
		while (temp->data != min)
		{
			move_rb(ps);
			temp = ps->stack_b;
		}
		return ;
	}
}