/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:51:35 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/08 14:55:21 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void big_stack(t_ps *ps)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	value;
	int	size;

	size = ps->size_stack_a;
	max_bits = 0;
	max_num = (size - 1);
	while((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (!check_if_complete(ps))
	{
		j = 0;
		while (j < size)
		{
			value = ps->stack_a->data;
			j++;
			if (((value >> i)&1) == 1)
				move_ra(ps);
			else
				move_pb(ps);
		}
		i++;
		while(ps->size_stack_b > 1)
			move_pa(ps);
		if (check_if_complete(ps) == 1)
		{
			printf("movi%d\n", ps->movements);
			exit(0) ;
		}
	}
}