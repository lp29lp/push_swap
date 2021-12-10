/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 06:40:50 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/10 06:42:10 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_node
{
	struct s_node	*next;
	int				data;
}	t_node;

typedef struct s_ps
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_stack_a;
	int		size_stack_b;
	int		movements;
	int		limit;
	int		bottom;
	int		mid;
	int		top;
	int		min;
	int		max;
	int		next_min;
	int		first;
	int		last;
	int		c_chunk;
	int		last_position;
	int		first_position;
	int		hold_first;
	int		hold_second;
	int		value;
	int		i;
}	t_ps;

#endif