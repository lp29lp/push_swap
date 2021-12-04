/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:07:03 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/03 19:07:03 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*add_first(t_node *tail, int data)
{
	t_node	*new_node = new_node(data);

	if (new_node == NULL)
		return (NULL);
	if (tail == NULL)
		return (new_node);//primeiro node a ser criado
	else
	{
		t_node	*temp;
		tail = tail->next;
		new_node->prev = tail;
		new_node->next = temp;
		temp->prev = new_node;
		temp->next = new_node;
		return (tail);
	}
}
