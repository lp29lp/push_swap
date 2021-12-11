/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:41:14 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/11 01:33:52 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	back_to_a(t_ps *ps)
{
	t_node	*temp;
	int		i;

	ps->max = get_max(ps, 1);
	i = get_position(ps, ps->max);
	temp = ps->stack_b;
	while (temp)
	{
		if (ps->size_stack_b == 2)
			break ;
		if (temp->data == ps->max)
		{
			move_pa(ps);
			temp = ps->stack_b;
			ps->max = get_max(ps, 1);
			i = get_position(ps, ps->max);
		}
		else
		{
			check(ps, i);
			temp = ps->stack_b;
		}
	}
	move_pa(ps);
}

//move "max" to top
void	check(t_ps *ps, int i)
{
	if (i > (ps->size_stack_b / 2))
		move_rrb(ps, 0);
	else
		move_rb(ps);
}

int	get_position(t_ps *ps, int max)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = ps->stack_b;
	while (temp)
	{
		i++;
		if (temp->data == max)
			return (max);
		temp = temp->next;
	}
	return (0);
}
