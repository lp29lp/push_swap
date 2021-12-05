/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:53:34 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/05 00:53:34 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	move_sa(t_ps *ps)
{
	t_node	*temp;
	t_node	*aux;

	if (ps->size_stack_a <= 1)
		return ;
	temp = new_node(0);
	aux = ps->stack_a;
	temp->data = aux->data;
	aux->data = aux->next->data;
	aux->next->data = temp->data;
	ps->movements++;
	free(temp);
	write(1, "sa\n", 3);
}

void	move_sb(t_ps *ps)
{
	t_node	*temp;
	t_node	*aux;

	if (ps->size_stack_b <= 1)
		return ;
	temp = new_node(0);
	aux = ps->stack_b;
	temp->data = aux->data;
	aux->data = aux->next->data;
	aux->next->data = temp->data;
	ps->movements++;
	free(temp);
	write(1, "sb\n", 3);
}

void	move_ss(t_ps *ps)
{
	aux_ss(&ps->stack_a);
	aux_ss(&ps->stack_b);
	write(1, "ss\n",3);
	ps->movements++;
}

void	move_ra(t_ps *ps)
{
	rotate(&ps->stack_a);
	write(1, "ra\n", 3);
	ps->movements++;
}

void	move_rb(t_ps *ps)
{
	rotate(&ps->stack_b);
	write(1, "rb\n", 3);
	ps->movements++;
}
