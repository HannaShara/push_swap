/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:38:55 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/07 12:38:58 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_chunk(t_stack **stack, int until)
{
	t_stack	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->index <= until)
			return (1);
		temp = temp->next;
	}
	return (0);
}
/*
int	is_biggest(t_stack **stack, int target)
{

}*/
int	best_spot(t_stack **stack_a, t_stack **stack_b)
{
	int		to_move;
	t_stack	*temp;

	position_update(stack_b);
	to_move = (*stack_a)->index;
	//printf("%d to move\n", to_move);
	temp = *stack_b;
	while (temp != NULL && temp->next != NULL)
	{
		//printf("temp index %d et temp next index %d\n", temp->index, temp->next->index);
		if (to_move > temp->index && to_move < temp->next->index)
			return (temp->pos);
		temp = temp->next;
	}
	//printf ("slkgj");
	return ((*stack_b)->pos);
}

void	move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;

	if (stack_size(*stack_b) > 1)
	{
		pos = best_spot(stack_a, stack_b);
		//printf ("%d pos et %d size \n", pos, i);
		if (pos <= stack_size(*stack_b) / 2)
		{
			while ((*stack_b)->pos != pos)
				rb(stack_b);
		}
		else if (pos > stack_size(*stack_b) / 2)
		{
			while ((*stack_b)->pos != pos)
				rrb(stack_b);
		}
	}
	pb(stack_a, stack_b);
}

void	chunk(t_stack **stack_a, t_stack **stack_b, int until)
{
	t_stack	*pointer_top;
	int		index_top;
	int		index_bottom;
	int		pos_top;
	int		pos_bottom;

	if (!check_chunk(stack_a, until))
		return ;
	position_update(stack_a);
		pointer_top = *stack_a;
	while (pointer_top->index > until)
		pointer_top = pointer_top->next;
	index_top = pointer_top->index;
	pos_top = pointer_top->pos;
	while (pointer_top != NULL)
	{
		if (pointer_top->index <= until)
		{
			index_bottom = pointer_top->index;
			pos_bottom = pointer_top->pos;
		}
		pointer_top = pointer_top->next;
	}
	int road_bottom = stack_size(*stack_a) - pos_bottom + 1;
	if (pos_top < road_bottom)
	{
		while ((*stack_a)->index != index_top)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->index != index_bottom)
			rra(stack_a);
	}
	move_to_b(stack_a, stack_b);
	chunk(stack_a, stack_b, until);
}
