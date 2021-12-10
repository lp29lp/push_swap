/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:17:01 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/10 06:34:28 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_if_complete(t_ps *ps)
{
	t_node	*temp;
	int		prev_numb;

	prev_numb = 0;
	temp = ps->stack_a;
	while (temp->next)
	{
		prev_numb = temp->data;
		temp = temp->next;
		if (prev_numb > temp->data)
			return (0);
	}
	free_stack(ps);
	exit(1);
	return (1);
}
