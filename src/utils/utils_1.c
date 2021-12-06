/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:17:01 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/06 20:41:48 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	check_if_complete(t_ps *ps)
{
	t_node	*temp;
	int		prev_numb;

	prev_numb = 0;
	temp = ps->stack_a;
	while(temp->next)
	{
		prev_numb = temp->data;
		temp = temp->next;
		if (prev_numb > temp->data)
			return (1);
	}
	return (0);
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}