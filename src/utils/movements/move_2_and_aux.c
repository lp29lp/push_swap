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

#include "../../../include/push_swap.h"

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