/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:33:12 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/05 14:33:12 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	move_rr(t_ps *ps)
{
	rotate(&ps->stack_a);
	rotate(&ps->stack_b);
	write(1, "rr\n", 3);
	ps->movements++;
}

void	move_pb(t_ps *ps)
{
	t_node	*aux;
	t_node	*new_stack;

	if (ps->stack_b == NULL)
		ps->stack_b = new_node(0);
	if (ps->size_stack_a == 0)
		return ;
	aux = ps->stack_a;
	new_stack = aux->next;
	if (ps->size_stack_b == 1)
	{
		aux_move_pb(ps, new_stack, aux);
		return ;
	}
	aux->next = NULL;
	aux->next = ps->stack_b;
	ps->stack_a = new_stack;
	ps->stack_b = aux;
	ps->size_stack_b++;
	ps->size_stack_a--;
	ps->movements++;
	write(1, "pb\n", 3);
}

void	move_pa(t_ps *ps)
{
	t_node	*aux;
	t_node	*new_stack;

	if (ps->size_stack_b == 1)
		return ;
	new_stack = ps->stack_b->next;
	aux = ps->stack_b;
	aux->next = NULL;
	if (ps->size_stack_a == 0)
	{
		aux_move_pa(ps, new_stack, aux);
		return ;
	}
	aux->next = ps->stack_a;
	ps->stack_b = new_stack;
	ps->stack_a = aux;
	ps->size_stack_b--;
	ps->size_stack_a++;
	ps->movements++;
	write(1, "pa\n", 3);
}

void	move_rra(t_ps *ps, int info)
{
	t_node	*aux;
	t_node	*last;
	t_node	*temp;

	aux = ps->stack_a;
	temp = aux;
	while (aux->next->next)
		aux = aux->next;
	last = aux->next;
	aux->next = NULL;
	last->next = temp;
	ps->stack_a = last;
	if (info == 1)
		return ;
	ps->movements++;
	write(1, "rra\n", 4);
}

void	move_rrb(t_ps *ps, int info)
{
	t_node	*aux;
	t_node	*last;
	t_node	*temp;

	aux = ps->stack_b;
	temp = aux;
	while (aux->next->next)
		aux = aux->next;
	last = aux->next;
	aux->next = NULL;
	last->next = temp;
	ps->stack_b = last;
	if (info == 1)
		return ;
	ps->movements++;
	write(1, "rrb\n", 4);
}
