/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:38:36 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/07 15:38:38 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	worst(t_stack **stack_b, int key)
{
	t_stack	*temp;
	int		pos_key;
	int		size_b;

	temp = *stack_b;
	position_update(stack_b);
	while (temp->index != key)
		temp = temp->next;
	pos_key = temp->pos;
	size_b = stack_size(*stack_b);
	if (pos_key < size_b / 2)
	{
		while ((*stack_b)->pos != pos_key)
			rb(stack_b);
	}
	else if (pos_key >= size_b / 2)
	{
		while ((*stack_b)->pos != pos_key)
			rrb(stack_b);
	}
}

void	research_next_cheap(t_stack **stack_b, int key)
{
	int		size_b;
	int		pos_key;
	t_stack	*temp;

	temp = *stack_b;
	position_update(stack_b);
	size_b = stack_size(*stack_b);
	while (temp->index != key)
		temp = temp->next;
	pos_key = temp->pos;
	if (pos_key < size_b / 3)
	{
		while ((*stack_b)->pos != pos_key)
			rb(stack_b);
	}
	else if (pos_key >= size_b - size_b / 3)
	{
		while ((*stack_b)->pos != pos_key)
			rrb(stack_b);
	}
	else
		worst(stack_b, key + 1);
}

void	research_next(t_stack **stack_a, t_stack **stack_b)
{
	int		key;
	int		size_b;
	int		pos_key;
	t_stack	*temp;

	position_update(stack_b);
	temp = *stack_b;
	if ((*stack_a)->next->index - (*stack_a)->index == 2)
		key = ((*stack_a)->index) + 1;
	else
		key = ((*stack_a)->index) - 1;
	size_b = stack_size(*stack_b);
	if (size_b == 1)
	{
		pa(stack_a, stack_b);
		return ;
	}
	while (temp->index != key)
		temp = temp->next;
	pos_key = temp->pos;
	if (pos_key < size_b / 3)
	{
		while ((*stack_b)->pos != pos_key)
			rb(stack_b);
	}
	else if (pos_key >= size_b - size_b / 3)
	{
		while ((*stack_b)->pos != pos_key)
			rrb(stack_b);
	}
	else
	{
		if ((*stack_a)->next->index - (*stack_a)->index == 2)
			worst(stack_b, key);
		else
			research_next_cheap(stack_b, key - 1);
	}
	pa(stack_a, stack_b);
}
