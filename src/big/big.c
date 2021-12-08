/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:58:21 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/08 18:38:59 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	big_stack(t_ps *ps)
{
	int	bigf_chunk;

	bigf_chunk = f_chunk(ps);// maior numero ate 25x q seja maior q o menor entretando nao literalmente precisa ser o maior numero de todo da lista
	while (ps->size_stack_a > 0)//esvazia a stack a
	{
		if (ps->size_stack_a == 1)
		{
			check_send(ps, ps->stack_a->data);
			move_pb(ps);
			break ;
		}
		if (ps->i == ps->c_chunk)
		{
			ps->c_chunk = 0;
			bigf_chunk = f_chunk(ps);
			ps->i = 0;
		}
		check_swap(ps, bigf_chunk);
		ps->i++;
	}
	ps->stack_a = new_node(0);
	back_to_a(ps);
}


void	check_swap(t_ps *ps, int bigf_chunk)//ve se vale a pena move o menor ou o maior
{
	int	half;

	half = (ps->size_stack_a / 2);
	ps->hold_second = get_number(ps, bigf_chunk);//pega o numero mais proximo do maior ou ele mesmo e pega o tanto de posicao ate ele
	if (ps->first_position <= half - (ps->last_position - half))
		parse_to_send(ps);
	else
		check_second(ps);
	return ;
}

int	get_number(t_ps *ps, int bigf_chunk)
{
	t_node	*aux;
	int		num;

	ps->last_position = 0;
	num = 0;
	aux = ps->stack_a;
	while (aux)
	{
		if (aux->data <= bigf_chunk)//se stack < q 25(bigf_chunk e o maior numero) se n bigf_chunk e o maior numero do chunk atual(vigesimo quinto)
			num = aux->data;
		aux = aux->next;
	}
	aux = ps->stack_a;
	while (aux)//conta quantas posicao tem ate bigf_chunk/num
	{
		if (aux->data == num)
			return (num);
		aux = aux->next;
		ps->last_position++;
	}
	return (num);
}

int	f_chunk(t_ps *ps)
{
	t_node	*temp;
	t_node	*aux;

	ps->max = INT_MAX;
	aux = ps->stack_a;
	ps->min = get_min(ps);
	while(ps->stack_a)
	{
		temp = ps->stack_a;
		while(temp)
		{
			if (temp->data > ps->min && temp->data < ps->max)//procura o numero mais proximo do menor no comeco da lista ou o maior numero ate 25x q seja maior q o menor entretando nao literalmente precisa ser o maior numero de todo da lista
				ps->max = temp->data;
			temp = temp->next;
		}
		ps->c_chunk++;
		aux = aux->next;
		if (ps->c_chunk == 25 || aux->next == NULL)
			return (ps->max);
		ps->min = ps->max;
		ps->max = INT_MAX;
	}
	return (ps->max);
}

void	check_second(t_ps *ps)
{
	t_node	*temp;

	temp = ps->stack_a;
	if (ps->last_position == 0)
	{
		check_send(ps, ps->hold_second);
		move_pb(ps);
		return ;
	}
	while (temp)
	{
		if (ps->size_stack_a == 1)
			return ;
		temp = temp->next;
		temp = ps->stack_a;
		if (temp->data == ps->hold_second)
		{
			check_send(ps, ps->hold_second);//menor numero
			move_pb(ps);//manda para b
			return ;
		}
		move_rra(ps, 0);
	}
}

