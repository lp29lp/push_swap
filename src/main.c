/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:19:10 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/10/09 20:09:38 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
TODO	()FREE STACK TWO POINTERS + ()TEST ARGUMENTS
		!MAYBE STACK IN A STRUCT?
*/

#include "./include/push_swap.h"

int	main(int ac, char **av)
{
	int	i;
	int **tmp;

	if (ac < 1)
	{
		herror("Arguments invalid, need more");
		return (0);
	}
	i = 0;
	while (av[i] != NULL)
	{
		stack[i][0] = ft_julius(av[i], stack);
		if (tmp < 0)
		{
			herror("Numbers equals");
			return (0);
			free_stack();
		}
		i++;
	}
}

int	julius(char numb, int **stack)
{
	int num;

	num = ft_atoi(numb);
	while (stack[i][0] != NULL)
	{
		if (stack[i][0] == num)
			return (-1);
		else
			i++;
	}
	return (num);
}
