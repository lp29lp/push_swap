/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:17:01 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/10 11:33:18 by lpaulo-d         ###   ########.fr       */
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

int	ft_atoi(const char *nptr, t_ps *ps)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10 + (*nptr++ - '0');
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
	{
		free_stack(ps);
		ft_putendl_fd("Error", 1);
		exit(1);
	}
	return ((int)(result * sign));
}
