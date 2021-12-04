/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:45:38 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/03 23:45:38 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*new_node(int data)
{
	t_node	*node;
	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;//
	node->prev = data;
	return (node);
}

