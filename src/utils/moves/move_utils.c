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

void    aux_ss(t_node **node)
{
	t_node	*tmp;
	t_node	*aux;

	tmp = new_node(0);
	aux = *node;
	tmp->data = aux->data;
	aux->data = aux->next->data;
	aux->next->data = tmp->data;
}