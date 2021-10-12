/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:19:10 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/10/11 22:00:48 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	dora(char **get_size, char *numb, int **tmp, int info);

int	main(int ac, char **av)
{
	int	x;
	int	len;
	int **tmp;
	int	n_actual;

	if (ac <= 1)
	{
		ft_putendl_fd("Need more arguments.", 1);
		exit(1);
	}
	x = 1;
	len = dora(av, NULL, tmp, 0);
	while (av[x] != NULL)
	{
		n_actual = dora(NULL, av[x], tmp, x);
		x++;
	}
	printf("len: %d\n", len);
}

static int	dora(char **get_size, char *numb, int **tmp, int info)
{
	int	x;
	int	n_size;
	int	num;
	x = 0;
	if (info == 0)
	{
		while (get_size[x] != NULL)
			x++;
		tmp = (int **)malloc(sizeof(int *) * x);
		return (x - 1);
	}
	else
	{
		if (info != 1)
		{
			num = ft_atoi(numb);
			while (tmp[x] < info)
			{
				if (tmp[x] == num)
				{
					ft_putendl_fd("Numbers equals.", 1);
					exit(1);
				}
				x++;
			}
		}
		tmp[info] = (int *)malloc(sizeof(int) * ft_strlen(numb));
		
	}
}