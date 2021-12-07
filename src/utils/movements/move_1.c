/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:33:12 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/05 14:33:12 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	move_rr(t_ps *ps)
{
	rotate(&ps->stack_a);
	rotate(&ps->stack_b);
	write(1, "rr\n", 3);
	ps->movements++;
}

void	move_pb(t_ps *ps)
{
	t_node *aux;
	t_node *new_stack;

	if (ps->size_stack_a == 0)
		return ;
	aux = ps->stack_a;//primeira posicao
	new_stack = aux->next;//segunda posicao
	if (ps->size_stack_b == 1)
	{
		ps->stack_b->data = aux->data;
		ps->stack_a = new_stack;
		free(aux);
		aux = NULL;
		ps->size_stack_b++;
		ps->size_stack_a--;
		ps->movements++;
		write(1, "pb\n", 3);
		return ;
	}
	aux->next = NULL;//distaca a primeira 
	aux->next = ps->stack_b;//liga na primeira da stack b
	ps->stack_a = new_stack;//novo comeco stack a
	ps->stack_b = aux;//novo comeco para stack b
	ps->size_stack_b++;
	ps->size_stack_a--;
	ps->movements++;
	write(1, "pb\n", 3);
}

void	move_pa(t_ps *ps)
{
	t_node *aux;
	t_node *new_stack;

	if (ps->size_stack_b == 1)
		return ;
	new_stack = ps->stack_b->next;//segunda posicao stack b
	aux = ps->stack_b;//primeira posicao stack b
	aux->next = NULL;//destacou
	if (ps->size_stack_a == 0)
	{
		free (ps->stack_a);
		ps->stack_a = new_node(aux->data);
		ps->stack_b = new_stack; //novo comeco da stack b
		free(aux);
		aux = NULL;
		ps->size_stack_b--;
		ps->size_stack_a++;
		write(1, "pa\n", 3);
		return ;
	}
	aux->next = ps->stack_a;//ligou o destacado no comeco da stack a
	ps->stack_b = new_stack;//novo comeco para stack b
	ps->stack_a = aux;//novo comeco para stack a
	ps->size_stack_b--;
	ps->size_stack_a++;
	ps->movements++;
	write(1, "pa\n", 3);
}

void	move_rra(t_ps *ps, int info)
{
	t_node	*aux;
	t_node	*last;
	t_node	*temp;

	aux = ps->stack_a;
	temp = aux;
	while (aux->next->next)
		aux = aux->next;
	last = aux->next;
	aux->next = NULL;
	last->next = temp;
	ps->stack_a = last;
	if (info == 1)
		return ;
	ps->movements++;
	write(1, "rra\n", 4);
}

void	move_rrb(t_ps *ps, int info)
{
	t_node	*aux;
	t_node	*last;
	t_node	*temp;

	aux = ps->stack_b;//primeira posicao
	temp = aux;//primeira posicao
	while (aux->next->next)//procura o penultimo
		aux = aux->next;//sai como penultimo
	last = aux->next;//guarda ultima posicao
	aux->next = NULL;//destaca o penultimo da ultima deixando a ultima sozinha
	last->next = temp;
	ps->stack_b = last;
	if(info == 1)
		return ;
	ps->movements++;
	write(1, "rrb\n", 4);
}
