/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:19:10 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/10/12 03:44:33 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	dora(char **get_size, char *numb, int **tmp, int info);
static void	char_onlynumbers(char *number);

int	main(int ac, char **av)
{
	int	x;
	int	z;
	int	len;
	int **tmp;
	int	numb;
	int size;

	if (ac <= 1)
	{
		ft_putendl_fd("Need more arguments.", 1);
		exit(EXIT_FAILURE);
	}
	x = 1;
	z = 0;
	len = dora(av, NULL, tmp, -1);
	tmp = (int **)malloc(sizeof(int *) * len);
	if (!tmp)
		exit(EXIT_FAILURE);
	while (av[x] != NULL)
	{
		size = (int)ft_strlen(av[x]);
		tmp[z] = (int *)malloc(sizeof(int *) * size);
		if (!tmp[z])
			exit(EXIT_FAILURE);
		tmp[z][0] = dora(NULL, av[x], tmp, z);
		x++;
		z++;
	}
}

static int	dora(char **get_size, char *numb, int **tmp, int info)
{
	int	x;
	int	n_size;
	int	num;
	x = 0;
	if (info == -1)
	{
		while (get_size[x] != NULL)
			x++;
		return (x - 1);
	}
	else
	{
		char_onlynumbers(numb);
		num = ft_atoi(numb);
		while (x <= info)
		{
			if (tmp[x][0] == num)
			{
				ft_putendl_fd("Numbers equals.", 1);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		return (num);
	}
}

static void	char_onlynumbers(char *number)
{
	int	x;

	x = 0;
	while (number[x] != '\0')
	{
		if (number[x] >= '0' && number[x] <= '9')
			x++;
		else
		{
			ft_putendl_fd("Arguments invalid, use numbers.", 1);
			exit(EXIT_FAILURE);
		}
	}
}