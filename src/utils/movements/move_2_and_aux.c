/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 01:25:48 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/05 01:25:48 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	aux_ss(t_node **node)
{
	t_node	*temp;
	t_node	*aux;

	temp = new_node(0);
	aux = *node;
	temp->data = aux->data;
	aux->data = aux->next->data;
	aux->next->data = temp->data;
	free(temp);
}

void	rotate(t_node **node)
{
	t_node	*temp;
	t_node	*aux;
	t_node	*last;

	aux = (*node)->next;
	temp = aux;
	last = *node;
	last->next = NULL;
	while (aux->next)
		aux = aux->next;
	aux->next = last;
	*node = temp;
}

void	move_rrr(t_ps *ps)
{
	move_rra(ps, 1);
	move_rrb(ps, 1);
	ps->movements++;
	write(1, "rrr\n", 4);
}

void	aux_move_pb(t_ps *ps, t_node *new_stack, t_node *aux)
{
	ps->stack_b->data = aux->data;
	ps->stack_a = new_stack;
	free(aux);
	aux = NULL;
	ps->size_stack_b++;
	ps->size_stack_a--;
	ps->movements++;
	write(1, "pb\n", 3);
	return ;
}

void	aux_move_pa(t_ps *ps, t_node *new_stack, t_node *aux)
{
	free (ps->stack_a);
	ps->stack_a = new_node(aux->data);
	ps->stack_b = new_stack;
	free(aux);
	aux = NULL;
	ps->size_stack_b--;
	ps->size_stack_a++;
	write(1, "pa\n", 3);
	return ;
}
